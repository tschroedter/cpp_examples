/*
 * TemperaturesMonitor.cpp
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#include <string.h>
#include "TemperaturesMonitor.h"

#include <Common/Interfaces/IThreadInformationProvider.h>
#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensor.h"
#include "../../Interfaces/Monitors/Temperatures/ITemperatureSensorToStringConverter.h"
#include "../../Interfaces/Monitors/Temperatures/ITemperaturesMessageHandler.h"

using namespace Sauerteig::Monitors::Temperatures;

TemperaturesMonitor::TemperaturesMonitor(ILogger_SPtr logger,
                                         IThreadInformationProvider_SPtr provider,
                                         ITemperaturesMessageHandler_SPtr handler,
                                         ITemperatureSensorToStringConverter_SPtr converter)
        : m_logger(logger),
          m_provider(provider),
          m_handler(handler),
          m_converter(converter) {
    if (m_logger == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMonitor because 'logger' is null!",
                                                           "logger");
    }

    if (m_provider == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMonitor because 'provider' is null!",
                                                           "provider");
    }

    if (m_handler == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMonitor because 'handler' is null!",
                                                           "handler");
    }

    if (m_converter == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'converter' is null!", "converter");
    }

    m_logger->set_prefix("TemperaturesMonitor");
}

std::string TemperaturesMonitor::to_string() const {
    celsius inside_value = m_handler->get_inside_average_value();
    double inside_percent = m_handler->get_inside_average__percent_valid();

    std::string inside = m_converter->convert(inside_value, inside_percent);

    celsius outside_value = m_handler->get_outside_average_value();
    double outside_percent = m_handler->get_outside_average__percent_valid();

    std::string outside = m_converter->convert(outside_value, outside_percent);

    std::string message = "Current temperatures (Inside, Outside): " + inside + ", " + outside;

    return message;
}
