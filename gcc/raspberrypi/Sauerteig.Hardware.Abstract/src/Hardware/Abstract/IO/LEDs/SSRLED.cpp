/*
 * SSRLED.cpp
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#include "SSRLED.h"
#include "../../Interfaces/IO/SerialShiftRegister/ISSROutputs.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"

using namespace Hardware::Abstract::IO::LEDs;

SSRLED::SSRLED(ISSROutputs_SPtr ssr)
        : m_ssr(ssr) {
    if (m_ssr == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create SSRLED because 'm_ssr' is null!", "m_ssr");
    }
}

void SSRLED::on() {
    m_ssr->high(m_pin);
}

void SSRLED::off() {
    m_ssr->low(m_pin);
}

bool SSRLED::is_on() const {
    return m_ssr->is_high(m_pin);
}

void SSRLED::initialize(ssroutputpin pin) {
    m_pin = pin;
}
