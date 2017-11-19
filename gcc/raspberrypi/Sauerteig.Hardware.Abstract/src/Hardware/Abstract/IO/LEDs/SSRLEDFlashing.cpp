/*
 * SSRLEDFlashing.cpp
 *
 *  Created on: 16 Nov. 2017
 *      Author: tom
 */

#include "SSRLEDFlashing.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"

using namespace Hardware::Abstract::IO::LEDs;

SSRLEDFlashing::SSRLEDFlashing(ISSRLED_SPtr led,
                               ISwitchableFlashingServer_SPtr server)
        : m_led(led),
          m_server(server) {
    if (m_led == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create SSRLEDFlashing because 'm_led' is null!",
                "m_led");
    }

    if (m_server == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create SSRLEDFlashing because 'm_server' is null!",
                "m_server");
    }

    m_server->initialize(m_led);
}

void SSRLEDFlashing::on() {
    m_server->on();
}

void SSRLEDFlashing::off() {
    m_server->off();
}

bool SSRLEDFlashing::is_on() const {
    return m_server->is_on();
}

void SSRLEDFlashing::initialize(ssroutputpin pin) {
    m_led->initialize(pin);
}

void SSRLEDFlashing::start() {
    m_server->start();
}

void SSRLEDFlashing::stop() {
    m_server->stop();
}

void SSRLEDFlashing::set_on_interval_in_msec(uint interval) {
    m_server->set_on_interval_in_msec(interval);
}

void SSRLEDFlashing::set_off_interval_in_msec(uint interval) {
    m_server->set_off_interval_in_msec(interval);
}

uint SSRLEDFlashing::get_on_interval_in_msec() {
    return m_server->get_on_interval_in_msec();
}

uint SSRLEDFlashing::get_off_interval_in_msec() {
    return m_server->get_off_interval_in_msec();
}

bool SSRLEDFlashing::is_flashing_enable() const {
    return m_server->is_flashing_enable();
}

