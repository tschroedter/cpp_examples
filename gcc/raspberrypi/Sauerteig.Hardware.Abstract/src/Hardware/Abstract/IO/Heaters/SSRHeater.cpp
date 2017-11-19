/*
 * SSRHeater.cpp
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "SSRHeater.h"

using namespace Hardware::Abstract::IO::Heaters;

SSRHeater::SSRHeater(ISSROutputs_SPtr ssr)
        : m_ssr(ssr) {
    if (m_ssr == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create SSRHeater because 'm_ssr' is null!", "m_ssr");
    }
}

void SSRHeater::on() {
    m_ssr->high(m_pin);
}

void SSRHeater::off() {
    m_ssr->low(m_pin);
}

bool SSRHeater::is_on() const {
    return m_ssr->is_high(m_pin);
}

void SSRHeater::initialize(ssroutputpin pin) {
    m_pin = pin;
}
