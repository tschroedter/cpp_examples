/*
 * HeaterOnMessageHandler.cpp
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#include <memory.h>
#include <functional>
#include <thread>
#include <chrono>
#include "HeaterOnMessageHandler.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "../../BusNodes/HeaterOnMessageBusNode.h"
#include "../../Interfaces/Factories/IMessageBusNodeFactory.h"

using namespace std;
using namespace Sauerteig::BusNodes;
using namespace Common::Exceptions;

namespace Sauerteig {
namespace Monitors {
namespace Units {

HeaterOnMessageHandler::HeaterOnMessageHandler(ILogger_SPtr logger,
                                               IMessageBusNodeFactory_SPtr<HeaterOnMessageBusNode> factory)
        : m_logger(logger) {
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create HeaterOnMessageHandler because 'logger' is null!", "logger");
    }

    if (factory == nullptr) {
        throw ArgumentInvalidException("Can't create HeaterOnMessageHandler because 'factory' is null!", "factory");
    }

    m_bus_node = factory->create(HEATER_ON_MESSAGE_HANDLER_SUBSCRIBER_ID);

    if (m_bus_node == nullptr) {
        throw ArgumentInvalidException("Can't create HeaterOnMessageHandler because 'bus_node' is null!", "bus_node");
    }

    m_logger->set_prefix("HeaterOnMessageHandler");
}

MessageIdType HeaterOnMessageHandler::get_last_message_id() {
    return m_bus_node->get_last_message_id();
}

}
}
}
