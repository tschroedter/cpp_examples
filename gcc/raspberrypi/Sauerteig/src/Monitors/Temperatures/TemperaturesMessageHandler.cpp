/*
 * TemperaturesMessageHandler.cpp
 *
 *  Created on: 16 Jan. 2018
 *      Author: tom
 */

#include <memory.h>
#include <functional>
#include <string.h>
#include "TemperaturesMessageHandler.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/Factories/IMessageBusNodeFactory.h"

#define SUBSCRIBER_ID "TemperaturesMessageHandler"

using namespace Common::Exceptions;
using namespace Sauerteig::Monitors::Temperatures;

namespace Sauerteig {
namespace Monitors {
namespace Temperatures {

TemperaturesMessageHandler::TemperaturesMessageHandler(ILogger_SPtr logger,
                                                       IMessageBusNodeFactory_SPtr<TemperaturesMessageBusNode> factory)
        : m_logger(logger) {
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'logger' is null!", "logger");
    }

    if (factory == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'factory' is null!",
                                       "factory");
    }

    m_bus_node = factory->create(SUBSCRIBER_ID);

    if (m_bus_node == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'bus_node' is null!",
                                       "bus_node");
    }

    m_logger->set_prefix("TemperaturesMessageHandler");
}

celsius TemperaturesMessageHandler::get_inside_average_value() const {
    return m_bus_node->get_inside_average_value();
}

double TemperaturesMessageHandler::get_inside_average__percent_valid() const {
    return m_bus_node->get_inside_average__percent_valid();
}

celsius TemperaturesMessageHandler::get_outside_average_value() const {
    return m_bus_node->get_outside_average_value();
}

double TemperaturesMessageHandler::get_outside_average__percent_valid() const {
    return m_bus_node->get_outside_average__percent_valid();
}

}
}
}
