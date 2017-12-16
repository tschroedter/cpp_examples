/*
 * TemperatureSensorHistoryData.cpp
 *
 *  Created on: 21 Nov. 2017
 *      Author: tom
 */

#include "TemperatureSensorHistoryData.h"

using namespace Hardware::Abstract::IO::Sensors;

void TemperatureSensorHistoryData::set_value(celsius value) {
    m_value = value;
}

void TemperatureSensorHistoryData::set_is_valid(bool is_valid) {
    m_is_valid = is_valid;
}

celsius TemperatureSensorHistoryData::get_value() const {
    return m_value;
}

bool TemperatureSensorHistoryData::is_valid() const {
    return m_is_valid;
}
