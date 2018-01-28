/*
 * PulseGeneratoreServer.cpp
 *
 *  Created on: 10 Nov. 2017
 *      Author: tom
 */

#include "PulseGeneratoreServer.h"
#include "../Interfaces/IO/ISwitchable.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/ILogger.h"
#include "Common/Interfaces/IThreadInformationProvider.h"

using namespace Hardware::Abstract::IO;

PulseGeneratoreServer::PulseGeneratoreServer(ILogger_SPtr logger, IThreadInformationProvider_SPtr provider)
        : m_logger(logger),
          m_provider(provider),
          m_switchable(nullptr) {
    if (m_logger == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create PulseGeneratoreServer because 'logger' is null!", "logger");
    }

    if (m_provider == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create PulseGeneratoreServer because 'provider' is null!", "provider");
    }

    m_logger->set_prefix("PulseGeneratoreServer");

    m_worker = std::thread { &PulseGeneratoreServer::run, this };

    std::string id = m_provider->thread_id_to_string(m_worker.get_id());

    m_logger->info("Created PulseGeneratoreServer worker thread with id: " + id);
}

void PulseGeneratoreServer::initialize(ISwitchable_SPtr switchable) {
    m_switchable = switchable;

    if (m_switchable == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't initialize PulseGeneratoreServer because 'm_switchable' is null!", "m_switchable");
    }

    m_switchable->off();
}

PulseGeneratoreServer::~PulseGeneratoreServer() {
    m_done.store(true);

    if (m_worker.joinable()) {
        m_worker.join();
    }
}

void PulseGeneratoreServer::do_one_flash() {
    m_switchable->on();

    std::this_thread::sleep_for(std::chrono::milliseconds(m_interval_on_in_msec.load()));

    m_switchable->off();

    std::this_thread::sleep_for(std::chrono::milliseconds(m_interval_off_in_msec.load()));
}

void PulseGeneratoreServer::run() {
    std::string pid = m_provider->get_thread_process_id_as_string();
    m_logger->info("PulseGeneratoreServer PID: " + pid);

    while (!this->m_done.load()) {
        while (this->m_is_flashing_enabled.load()) {
            if (m_interval_on_in_msec.load() == 0) {
                if (m_switchable->is_on()) {
                    m_switchable->off();
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                continue;
            }

            do_one_flash();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void PulseGeneratoreServer::start() {
    m_is_flashing_enabled.store(true);
}

void PulseGeneratoreServer::stop() {
    m_is_flashing_enabled.store(false);
}

void PulseGeneratoreServer::set_on_interval_in_msec(uint interval) {
    m_interval_on_in_msec.store(interval);
}

void PulseGeneratoreServer::set_off_interval_in_msec(uint interval) {
    m_interval_off_in_msec.store(interval);
}

uint PulseGeneratoreServer::get_on_interval_in_msec() {
    return m_interval_on_in_msec.load();
}

uint PulseGeneratoreServer::get_off_interval_in_msec() {
    return m_interval_off_in_msec.load();
}

void PulseGeneratoreServer::on() {
    m_switchable->on();
    m_is_flashing_enabled.store(false);
}

void PulseGeneratoreServer::off() {
    m_switchable->off();
    m_is_flashing_enabled.store(false);
}

bool PulseGeneratoreServer::is_flashing_enable() const {
    return m_is_flashing_enabled.load();
}

bool PulseGeneratoreServer::is_on() const {
    return m_switchable->is_on();
}

