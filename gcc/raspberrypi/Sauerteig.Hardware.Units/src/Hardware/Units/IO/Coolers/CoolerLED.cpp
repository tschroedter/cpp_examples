/*
 * CoolerLED.cpp
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#include "CoolerLED.h"

#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Hardware/Abstract/Interfaces/IO/LEDs/ISSRLED.h"

#define DEFAULT_SSR_OUTPUT_PIN ((ssroutputpin) 1)

using namespace Hardware::Units::IO::Coolers;

CoolerLED::CoolerLED(ISSRLEDFlashing_SPtr led)
        : m_led(led) {
    if (m_led == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create CoolerLED because 'm_led' is null!", "m_led");
    }

    m_led->initialize(DEFAULT_SSR_OUTPUT_PIN);
}

void CoolerLED::on() {
    m_led->on();
}

void CoolerLED::off() {
    m_led->off();
}

bool CoolerLED::is_on() const {
    return m_led->is_on();
}

void CoolerLED::start() {
    m_led->start();
}

void CoolerLED::stop() {
    m_led->stop();
}

void CoolerLED::set_on_interval_in_msec(uint interval) {
    m_led->set_on_interval_in_msec(interval);
}

void CoolerLED::set_off_interval_in_msec(uint interval) {
    m_led->set_off_interval_in_msec(interval);
}

uint CoolerLED::get_on_interval_in_msec() {
    return m_led->get_on_interval_in_msec();
}

uint CoolerLED::get_off_interval_in_msec() {
    return m_led->get_off_interval_in_msec();
}

bool CoolerLED::is_flashing_enable() const {
    return m_led->is_flashing_enable();
}
