/*
 * LEDFlashingServer.cpp
 *
 *  Created on: 9 Nov. 2017
 *      Author: tom
 */

#include <iostream>
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../Interfaces/IO/ISwitchable.h"
#include "../Interfaces/IO/IPulseGeneratoreServer.h"
#include "SwitchableFlashingServer.h"

using namespace Hardware::Abstract::IO;

SwitchableFlashingServer::SwitchableFlashingServer(IPulseGeneratoreServer_SPtr server)
        : m_server(server) {
    if (m_server == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create LEDFlashingServer because 'm_server' is null!",
                                                           "m_server");
    }
}

SwitchableFlashingServer::~SwitchableFlashingServer() {
    m_server->stop();
}

void SwitchableFlashingServer::initialize(ISwitchable_SPtr switchable) {
    m_switchable = switchable;

    if (m_switchable == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't initialize SwitchableFlashingServer because 'm_switchable' is null!", "m_switchable");
    }

    m_server->initialize(switchable);
}

void SwitchableFlashingServer::on() {
    m_server->on();
}

void SwitchableFlashingServer::off() {
    m_server->off();
}

bool SwitchableFlashingServer::is_on() const {
    return m_server->is_on();
}

void SwitchableFlashingServer::start() {
    m_server->start();
}

void SwitchableFlashingServer::stop() {
    m_server->stop();
}

void SwitchableFlashingServer::set_on_interval_in_msec(uint interval) {
    m_server->set_on_interval_in_msec(interval);
}

void SwitchableFlashingServer::set_off_interval_in_msec(uint interval) {
    m_server->set_off_interval_in_msec(interval);
}

uint SwitchableFlashingServer::get_on_interval_in_msec() {
    return m_server->get_on_interval_in_msec();
}

uint SwitchableFlashingServer::get_off_interval_in_msec() {
    return m_server->get_off_interval_in_msec();
}

bool SwitchableFlashingServer::is_flashing_enable() const {
    return m_server->is_flashing_enable();
}

