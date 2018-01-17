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
#include "../../Interfaces/Factories/ITemperaturesMessageBusNodeFactory.h"
#include "../../Messages/TemperaturesMessage.h"

#define SUBSCRIBER_ID "TemperaturesMessageHandler"

namespace Sauerteig {
namespace Monitors {
namespace Temperatures {

TemperaturesMessageHandler::TemperaturesMessageHandler(
        ILogger_SPtr logger,
        ITemperaturesMessageBusNodeFactory_SPtr bus_node_factory)
: m_logger(logger) {
    if (m_logger == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'logger' is null!",
                                                           "logger");
    }

    if (bus_node_factory == nullptr) {
         throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'bus_node_factory' is null!",
                                                            "bus_node_factory");
    }

    m_bus_node = bus_node_factory->create(SUBSCRIBER_ID);

    if (m_bus_node == nullptr) {
         throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'bus_node' is null!",
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
