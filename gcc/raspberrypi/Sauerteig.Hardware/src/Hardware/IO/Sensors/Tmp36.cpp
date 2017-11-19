/*
 * Tmp36.cpp
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#include "Tmp36.h"
#include "../../Interfaces/IO/Sensors/ITmp36Logic.h"
#include "../../Interfaces/IO/AnalogeDigitalConverters/IADC.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Exceptions/ADCException.h"
#include "Common/Exceptions/Tmp36Exception.h"

using namespace Hardware::IO::Sensors;

Tmp36::Tmp36(ITmp36Logic_SPtr logic)
        : m_logic(logic) {
    if (m_logic == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create Tmp36 because 'm_logic' is null!", "m_logic");
    }
}

Tmp36::~Tmp36() {
}

void Tmp36::initialize(IADC_SPtr adc, adcchannel channel) {
    m_adc = adc;
    m_channel = channel;

    if (m_adc == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't initialize Tmp36 because 'm_adc' is null!", "m_adc");
    }
}

bool Tmp36::is_value_valid() const {
    return (m_is_valid);
}

void Tmp36::do_refresh() {
    m_adc->read_value_for_channel(m_channel);
    m_value_raw = (uint) (m_adc->get_value_for_channel(m_channel));
    m_is_valid = m_adc->is_value_valid_for_channel(m_channel);
    m_value = m_logic->raw_to_celsius(m_value_raw);
}

void Tmp36::refresh() {
    if (m_adc == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't refresh Tmp36 because 'm_adc' is null! Call initialize first!",
                "m_adc");
    }

    try {
        do_refresh();
    } catch (Common::Exceptions::ADCException & ex) {
        throw Common::Exceptions::Tmp36Exception(
                "Can't refresh Tmp36 because of an ADCExeption: "
                        + ex.get_message());
    }
}

celsius Tmp36::get_value() const {
    return (m_value);
}

uint Tmp36::get_value_raw() const {
    return (m_value_raw);
}

