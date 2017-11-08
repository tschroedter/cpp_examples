/*
 * Tmp36.cpp
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#include "Tmp36.h"
#include "../../Interfaces/IO/AnalogeDigitalConverters/IADCTemperatures.h"
#include "./Common/Exceptions/ArgumentInvalidExceptions.h"

Tmp36::Tmp36(IADCTemperatures_SPtr adc)
        : m_adc(adc),
          m_channel((uint) 0) {
    if (m_adc == nullptr) {
        throw ArgumentInvalidException(
                "Can't create Tmp36 because 'm_adc' is null!", "m_adc");
    }
}

Tmp36::~Tmp36() {
}

void Tmp36::initialize(uint channel) {
    m_channel = channel;
}

bool Tmp36::is_value_valid() const {
    return (m_is_valid);
}

void Tmp36::refresh() {
    m_adc->read_value_for_channel(m_channel);
    m_value_raw = (uint) m_adc->get_value_for_channel(m_channel);
    m_is_valid = m_adc->is_value_valid_for_channel(m_channel);

    // The voltage out is 0V at -50°C and 1.75V at 125°C. You can easily calculate
    // the temperature from the voltage in millivolts: Temp °C = 100*(reading in V) - 50
    double vr = 3.3 * m_value_raw / 255.0;
    m_value = (100.0 * vr) - 50.0;

}

uint Tmp36::get_value() const {
    return (m_value);
}

uint Tmp36::get_value_raw() const {
    return (m_value_raw);
}

