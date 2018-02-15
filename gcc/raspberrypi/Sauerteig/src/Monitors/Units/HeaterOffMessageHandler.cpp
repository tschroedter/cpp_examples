/*
 * HeaterOffMessageHandler.cpp
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#include <memory.h>
#include <functional>
#include <thread>
#include <chrono>
#include "HeaterOffMessageHandler.h"
#include "BaseOnOffMessageHandler.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "../../BusNodes/HeaterOffMessageBusNode.h"
#include "../../Interfaces/Factories/IMessageBusNodeFactory.h"

using namespace std;
using namespace Sauerteig::BusNodes;
using namespace Common::Exceptions;

namespace Sauerteig {
namespace Monitors {
namespace Units {

HeaterOffMessageHandler::HeaterOffMessageHandler(ILogger_SPtr logger,
                                               IMessageBusNodeFactory_SPtr<HeaterOffMessageBusNode> factory)
: BaseOnOffMessageHandler(logger, factory, HEATER_OFF_MESSAGE_HANDLER_SUBSCRIBER_ID) {
    m_logger->set_prefix("HeaterOffMessageHandler");
}

MessageIdType HeaterOffMessageHandler::get_last_message_id() {
    return m_bus_node->get_last_message_id();
}

}
}
}
