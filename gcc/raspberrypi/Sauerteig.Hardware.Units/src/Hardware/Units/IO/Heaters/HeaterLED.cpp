/*
 * HeaterLed.cpp
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#include "HeaterLED.h"

#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/IO/Heaters/IHeaterLED.h"

#define DEFAULT_SSR_OUTPUT_PIN ((ssroutputpin) 3)

using namespace Hardware::Units::IO::Heaters;

HeaterLED::HeaterLED(ISSRLEDFlashing_SPtr led)
        : m_led(led) {
    if (m_led == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create HeaterLed because 'm_led' is null!", "m_led");
    }

    m_led->initialize(DEFAULT_SSR_OUTPUT_PIN);
}

void HeaterLED::on() {
    m_led->on();
}

void HeaterLED::off() {
    m_led->off();
}

bool HeaterLED::is_on() const {
    return m_led->is_on();
}

void HeaterLED::start() {
    m_led->start();
}

void HeaterLED::stop() {
    m_led->stop();
}

void HeaterLED::set_on_interval_in_msec(uint interval) {
    m_led->set_on_interval_in_msec(interval);
}

void HeaterLED::set_off_interval_in_msec(uint interval) {
    m_led->set_off_interval_in_msec(interval);
}

uint HeaterLED::get_on_interval_in_msec() {
    return m_led->get_on_interval_in_msec();
}

uint HeaterLED::get_off_interval_in_msec() {
    return m_led->get_off_interval_in_msec();
}

bool HeaterLED::is_flashing_enable() const {
    return m_led->is_flashing_enable();
}
