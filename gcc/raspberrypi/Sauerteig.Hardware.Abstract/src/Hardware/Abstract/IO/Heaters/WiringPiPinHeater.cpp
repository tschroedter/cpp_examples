/*
 * WiringPiPinHeater.cpp
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#include "wiringPi.h"
#include "WiringPiPinHeater.h"
#include "../../Interfaces/IO/IWiringPiPin.h"
#include "Common/CommonTypes.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"

using namespace Hardware::Abstract::IO::Heaters;

WiringPiPinHeater::WiringPiPinHeater(IWiringPiPin_SPtr pin)
        : m_pin(pin) {
    if (m_pin == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create WiringPiPinHeater because 'm_pin' is null!",
                "m_pin");
    }
}

void WiringPiPinHeater::initialize(wiringpipin wiring_pi_pin) {
    m_pin->initialize(wiring_pi_pin, OUTPUT);
}

void WiringPiPinHeater::on() {
    m_pin->high();
}

void WiringPiPinHeater::off() {
    m_pin->low();
}

bool WiringPiPinHeater::is_on() const {
    return m_pin->is_high();
}
