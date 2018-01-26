/*
 * SSRHeater.cpp
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#include "SSRCooler.h"

#include "Common/Exceptions/ArgumentInvalidExceptions.h"

using namespace Common::Exceptions;
using namespace Hardware::Units::IO::Coolers;

SSRCooler::SSRCooler(ISSROutputs_SPtr ssr)
        : m_ssr(ssr) {
    if (m_ssr == nullptr) {
        throw ArgumentInvalidException("Can't create SSRCooler because 'm_ssr' is null!", "m_ssr");
    }
}

void SSRCooler::on() {
    m_ssr->high(m_pin);
}

void SSRCooler::off() {
    m_ssr->low(m_pin);
}

bool SSRCooler::is_on() const {
    return m_ssr->is_high(m_pin);
}

void SSRCooler::initialize(ssroutputpin pin) {
    m_pin = pin;
}
