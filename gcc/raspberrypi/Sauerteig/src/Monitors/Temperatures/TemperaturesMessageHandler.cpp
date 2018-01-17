/*
 * TemperaturesMessageHandler.cpp
 *
 *  Created on: 16 Jan. 2018
 *      Author: tom
 */

#include <memory.h>
#include "TemperaturesMessageHandler.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/ILogger.h"
#include "../../Messages/TemperaturesMessage.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"

#define SUBSCRIBER_ID "TemperaturesMessageHandler"

namespace Sauerteig {
namespace Monitors {
namespace Temperatures {

TemperaturesMessageHandler::TemperaturesMessageHandler(
        ILogger_SPtr logger,
        IBus_SPtr bus)
: m_logger(logger), m_bus(bus) {
    if (m_logger == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'logger' is null!",
                                                           "logger");
    }

    if (m_bus == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'bus' is null!",
                                                           "bus");
    }

    m_bus_node = std::make_shared<TemperaturesMessageBusNode>(m_logger, m_bus, SUBSCRIBER_ID);

    if (m_bus_node == nullptr) {
         throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'bus_node' is null!",
                                                            "bus_node");
    }

    m_logger->set_prefix("TemperaturesMessageHandler");
}

std::string TemperaturesMessageHandler::to_string() {
    return std::string("Test");
}

}
}
}
