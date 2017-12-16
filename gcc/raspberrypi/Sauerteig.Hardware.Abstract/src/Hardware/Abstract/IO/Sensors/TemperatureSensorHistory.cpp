/*
 * TemperatureSensorHistory.cpp
 *
 *  Created on: 21 Nov. 2017
 *      Author: tom
 */

#include<assert.h>
#include "TemperatureSensorHistory.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensorHistory.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensorHistoryData.h"

using namespace Hardware::Abstract::IO::Sensors;

void TemperatureSensorHistory::push_back(
        ITemperatureSensorHistoryData_SPtr data) {
    m_past_data.push_back(data);

    if (m_past_data.size() > m_number_of_samples) {
        m_past_data.pop_front();
    }
}

void TemperatureSensorHistory::pop_front() {
    m_past_data.pop_front();
}

size_t TemperatureSensorHistory::size() const {
    return m_past_data.size();
}

ITemperatureSensorHistoryData_SPtr TemperatureSensorHistory::get_element_at(
        uint index) const {
    return m_past_data[index];
}

void TemperatureSensorHistory::set_number_of_samples(uint number_of_samples) {
    m_number_of_samples = number_of_samples < 1 ? 1 : number_of_samples;
}

uint TemperatureSensorHistory::get_number_of_samples() const {
    return m_number_of_samples;
}

void TemperatureSensorHistory::clear() {
    m_past_data.clear();
}
