/*
 * TemperaturesPublisher.cpp
 *
 *  Created on: 16 Jan. 2018
 *      Author: tom
 */

#include <memory>
#include "TemperaturesPublisher.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/ILogger.h"
#include "Common/Interfaces/IThreadInformationProvider.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensorWithStatistics.h"
#include "Hardware/Units/Interfaces/IO/Sensors/ITemperatureInside.h"
#include "Hardware/Units/Interfaces/IO/Sensors/ITemperatureOutside.h"
#include "InMemoryBus/IBus.h"
#include "../Messages/TemperaturesMessage.h"

using namespace std;
using namespace Common::Exceptions;
using namespace Sauerteig::Messages;

namespace Sauerteig {
namespace Publishers {

TemperaturesPublisher::TemperaturesPublisher(
        ILogger_SPtr logger,
        IBus_SPtr bus,
        IThreadInformationProvider_SPtr provider,
        ITemperatureInside_SPtr inside,
        ITemperatureOutside_SPtr outside,
        ITemperatureSensorWithStatistics_SPtr inside_with_statistics,
        ITemperatureSensorWithStatistics_SPtr outside_with_statistics)
        : m_logger(logger),
          m_bus(bus),
          m_provider(provider),
          m_inside(inside_with_statistics),
          m_outside(outside_with_statistics) {
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesMonitor because 'logger' is null!",
                                                           "logger");
    }

    if (m_bus == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesMonitor because 'bus' is null!",
                                                           "bus");
    }

    if (m_provider == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesMonitor because 'provider' is null!",
                                                           "provider");
    }

    if (inside == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesMonitor because 'inside' is null!",
                                                           "inside");
    }

    if (outside == nullptr) {
        throw ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'outside' is null!", "outside");
    }

    if (m_inside == nullptr) {
        throw ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'inside_with_statistics' is null!", "inside_with_statistics");
    }

    if (m_outside == nullptr) {
        throw ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'outside_with_statistics' is null!",
                "outside_with_statistics");
    }

    m_logger->set_prefix("TemperaturesPublisher");
    m_inside->initialize(inside);
    m_outside->initialize(outside);
}

void TemperaturesPublisher::publish() {
    m_inside->refresh();
    m_outside->refresh();

    auto message = make_shared<TemperaturesMessage>();

    message->inside_average_value = m_inside->get_average_value();
    message->inside_average_percent_valid =m_inside->get_average_percent_valid();
    message->outside_average_value = m_outside->get_average_value();
    message->outside_average_percent_valid = m_outside->get_average_percent_valid();

    m_bus->publish(message);

    m_logger->debug("Published 'TemperaturesMessage': " + message->to_string());
}

}
}
