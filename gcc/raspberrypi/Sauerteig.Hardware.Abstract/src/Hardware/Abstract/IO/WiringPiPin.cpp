/*
 * WiringPiPin.cpp
 *
 *  Created on: 11 Nov. 2017
 *      Author: tom
 */

#include "wiringPi.h"
#include "WiringPiPin.h"
#include "Common/CommonTypes.h"

using namespace Hardware::Abstract::IO;

void WiringPiPin::initialize(uint wiring_pi_pin, uint pin_mode) {
    m_pin = wiring_pi_pin;
    m_mode = pin_mode;

    pinMode(m_pin, m_mode);
}

uint WiringPiPin::get_pin() const {
    return m_pin;
}

void WiringPiPin::set_mode(uint pin_mode) {
    pinMode(m_pin, pin_mode);
}

uint WiringPiPin::get_mode() const {
    return m_mode;
}

void WiringPiPin::high() {
    m_is_high = true;

    digitalWrite(m_pin, HIGH);
}

void WiringPiPin::low() {
    m_is_high = false;

    digitalWrite(m_pin, LOW);
}

bool WiringPiPin::is_high() const {
    return m_is_high;
}
