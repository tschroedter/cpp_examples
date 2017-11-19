/*
 * ADCTmp36.cpp
 *
 *  Created on: 14 Nov. 2017
 *      Author: tom
 */

#include "Hypodermic/FactoryWrapper.h"
#include "ADCTmp36.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/IO/AnalogeDigitalConverters/IADCInputs.h"

#define CHANNEL_0 ((adcchannel) 0)

using namespace Hardware::Abstract::IO::Sensors;

ADCTmp36::ADCTmp36(IADCInputs_SPtr adc, ITmp36_SPtr tmp36)
        : m_adc(adc),
          m_tmp36(tmp36) {
    if (m_adc == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create ADCTmp36 because 'm_adc' is null!", "m_adc");
    }

    if (m_tmp36 == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create ADCTmp36 because 'm_tmp36' is null!", "m_tmp36");
    }
}

void ADCTmp36::initialize(adcchannel channel) {
    m_tmp36->initialize(m_adc, channel);
}

bool ADCTmp36::is_value_valid() const {
    return m_tmp36->is_value_valid();
}

celsius ADCTmp36::get_value() const {
    return m_tmp36->get_value();
}

void ADCTmp36::refresh() {
    m_tmp36->refresh();
}

