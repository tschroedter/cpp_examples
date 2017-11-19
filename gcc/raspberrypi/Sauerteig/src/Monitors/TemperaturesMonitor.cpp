/*
 * TemperaturesMonitor.cpp
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#include <string>
#include <chrono>
#include <ctime>
#include "TemperaturesMonitor.h"
#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensor.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureInside.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureOutside.h"
#include "../Interfaces/Monitors/ITemperatureSensorToStringConverter.h"

using namespace Sauerteig::Monitors;

TemperaturesMonitor::TemperaturesMonitor(
        ILogger_SPtr logger, ITemperatureInside_SPtr inside,
        ITemperatureOutside_SPtr outside,
        ITemperatureSensorToStringConverter_SPtr converter)
        : m_logger(logger),
          m_inside(inside),
          m_outside(outside),
          m_converter(converter) {
    if (m_logger == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'm_logger' is null!",
                "m_logger");
    }

    if (m_inside == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'm_inside' is null!",
                "m_inside");
    }

    if (m_outside == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'm_outside' is null!",
                "m_outside");
    }

    if (m_converter == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'm_converter' is null!",
                "m_converter");
    }
}

std::string TemperaturesMonitor::create_timestamp() const {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    std::string datetime { std::ctime(&now_time_t) };
    std::string datetime_without_return = datetime.substr(
            0, datetime.length() - 1);

    std::string text = "[" + datetime_without_return + "] ";

    return (text);
}

std::string TemperaturesMonitor::to_string() const {
    std::string timestamp = create_timestamp();

    std::string inside = m_converter->convert(m_inside);
    std::string outside = m_converter->convert(m_outside);

    std::string message = timestamp + "Current temperatures (Inside, Outside): "
            + inside + ", " + outside;

    return message;
}

