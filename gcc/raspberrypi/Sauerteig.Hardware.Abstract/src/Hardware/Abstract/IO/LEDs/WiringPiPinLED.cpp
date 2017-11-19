/*
 * LED.cpp
 *
 *  Created on: 8 Nov. 2017
 *      Author: tom
 */

#include "WiringPiPinLED.h"

#include <iostream>
#include "Common/CommonTypes.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "wiringPi.h"

using namespace Hardware::Abstract::IO::LEDs;

WiringPiPinLED::WiringPiPinLED(IWiringPiPin_SPtr pin)
        : m_pin(pin) {
    if (m_pin == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create LED because 'm_pin' is null!", "m_pin");
    }
}

// ILED
void WiringPiPinLED::initialize(uint wiring_pi_pin) {
    m_pin->initialize(wiring_pi_pin, OUTPUT);
}

// ISwitchable
void WiringPiPinLED::on() {
    m_pin->high();
}

void WiringPiPinLED::off() {
    m_pin->low();
}

bool WiringPiPinLED::is_on() const {
    return m_pin->is_high();
}
