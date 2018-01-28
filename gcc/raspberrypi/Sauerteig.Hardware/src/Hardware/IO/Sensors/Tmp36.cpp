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
#include "Common/Interfaces/ILogger.h"

using namespace Common::Exceptions;
using namespace Hardware::IO::Sensors;

Tmp36::Tmp36(ILogger_SPtr logger, ITmp36Logic_SPtr logic)
        : m_logger(logger),
          m_logic(logic) {
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create Tmp36 because 'm_logger' is null!", "m_logger");
    }

    if (m_logic == nullptr) {
        throw ArgumentInvalidException("Can't create Tmp36 because 'm_logic' is null!", "m_logic");
    }

    m_logger->set_prefix("Tmp36");
}

Tmp36::~Tmp36() {
}

void Tmp36::initialize(IADC_SPtr adc, adcchannel channel) {
    m_adc = adc;
    m_channel = channel;

    if (m_adc == nullptr) {
        throw ArgumentInvalidException("Can't initialize Tmp36 because 'm_adc' is null!", "m_adc");
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
        throw ArgumentInvalidException("Can't refresh Tmp36 because 'm_adc' is null! Call initialize first!", "m_adc");
    }

    try {
        m_logger->debug("Refreshing...");

        do_refresh();
    } catch (ADCException & ex) {
        throw Tmp36Exception("Can't refresh Tmp36 because of an ADCExeption: " + ex.get_message());
    }
}

celsius Tmp36::get_value() const {
    m_logger->debug("Current temperature: " + std::to_string(m_value) + " C");

    return (m_value);
}

uint Tmp36::get_value_raw() const {
    m_logger->debug("Current raw value: " + std::to_string(m_value_raw));

    return (m_value_raw);
}

