/*
 * TemperatureSensorWithStatistics.cpp
 *
 *  Created on: 20 Nov. 2017
 *      Author: tom
 */

#include "TemperatureSensorWithStatistics.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"

#include <deque>
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "TemperatureSensorHistoryData.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensorWithStatistics.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensorHistory.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensorHistoryData.h"

using namespace Hardware::Abstract::IO::Sensors;

TemperatureSensorWithStatistics::TemperatureSensorWithStatistics(
        ILogger_SPtr logger, ITemperatureSensorHistory_SPtr history)
        : m_logger(logger),
          m_history(history) {
    if (m_logger == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperatureInside because 'm_logger' is null!",
                "m_logger");
    }

    if (m_history == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperatureSensorWithStatistics because 'm_history' is null!",
                "m_history");
    }
}

void TemperatureSensorWithStatistics::validate_sensor() const {
    if (m_sensor == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "TemperatureSensorWithStatistics is invalid because 'm_sensor' is null!",
                "m_sensor");
    }
}
void TemperatureSensorWithStatistics::initialize(
        ITemperatureSensor_SPtr sensor) {
    m_history->clear();

    m_sensor = sensor;

    validate_sensor();
}

bool TemperatureSensorWithStatistics::is_value_valid() const {
    return (m_sensor->is_value_valid());
}

celsius TemperatureSensorWithStatistics::get_value() const {
    return (m_sensor->get_value());
}

void TemperatureSensorWithStatistics::update_statistics() {
    celsius sum = 0.0;
    uint count_valid = 0;

    for (uint i = 0; i < m_history->size(); i++) {
        auto data = m_history->get_element_at(i);

        if ((data->is_valid()) == true) {
            sum += data->get_value();
            count_valid++;
        }
    }

    m_average_temperature = sum / count_valid;
    m_temperature_valid_percentage = count_valid * 100.0 / m_history->size();
}

void TemperatureSensorWithStatistics::refresh() {
    m_sensor->refresh();

    // TODO need factory with parameters
    auto data = std::make_shared<TemperatureSensorHistoryData>();
    data->set_value(m_sensor->get_value());
    data->set_is_valid(m_sensor->is_value_valid());

    m_history->push_back(data);

    update_statistics();
}

celsius TemperatureSensorWithStatistics::get_average_value() const {
    return m_average_temperature;
}

double TemperatureSensorWithStatistics::get_average_percent_valid() const {
    return m_temperature_valid_percentage;
}

void TemperatureSensorWithStatistics::set_number_of_samples(
        uint number_of_samples) {
    m_history->set_number_of_samples(number_of_samples);
}

uint TemperatureSensorWithStatistics::get_number_of_samples() const {
    return m_history->get_number_of_samples();
}
