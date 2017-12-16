/*
 * TemperaturesMonitor.cpp
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#include <string>
#include "TemperaturesMonitor.h"
#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensor.h"
#include "Hardware/Units/Interfaces/IO/Sensors/ITemperatureInside.h"
#include "Hardware/Units/Interfaces/IO/Sensors/ITemperatureOutside.h"
#include "../../Interfaces/Monitors/Temperatures/ITemperatureSensorToStringConverter.h"

using namespace Sauerteig::Monitors::Temperatures;

TemperaturesMonitor::TemperaturesMonitor(ILogger_SPtr logger, ITemperatureInside_SPtr inside,
                                         ITemperatureOutside_SPtr outside,
                                         ITemperatureSensorWithStatistics_SPtr inside_with_statistics,
                                         ITemperatureSensorWithStatistics_SPtr outside_with_statistics,
                                         ITemperatureSensorToStringConverter_SPtr converter)
        : m_logger(logger),
          m_inside(inside_with_statistics),
          m_outside(outside_with_statistics),
          m_converter(converter) {
    if (m_logger == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMonitor because 'logger' is null!",
                                                           "logger");
    }

    if (inside == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMonitor because 'inside' is null!",
                                                           "inside");
    }

    if (outside == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'outside' is null!", "outside");
    }

    if (m_inside == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'inside_with_statistics' is null!", "inside_with_statistics");
    }

    if (m_outside == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'outside_with_statistics' is null!",
                "outside_with_statistics");
    }

    if (m_converter == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'converter' is null!", "converter");
    }

    m_logger->set_prefix("TemperaturesMonitor");
    m_inside->initialize(inside);
    m_outside->initialize(outside);
}

std::string TemperaturesMonitor::to_string() const {
    m_inside->refresh();
    m_outside->refresh();

    std::string inside = m_converter->convert(m_inside);
    std::string outside = m_converter->convert(m_outside);

    std::string message = "Current temperatures (Inside, Outside): " + inside + ", " + outside;

    return message;
}

