/*
 * CoolerOffMessageHandler.cpp
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#include "CoolerOffMessageHandler.h"
#include "BaseOnOffMessageHandler.h"
#include "../../BusNodes/CoolerOffMessageBusNode.h"
#include "InMemoryBus/Common/BaseMessage.h"

using namespace std;

namespace Sauerteig {
namespace Monitors {
namespace Units {

CoolerOffMessageHandler::CoolerOffMessageHandler(ILogger_SPtr logger, IMessageBusNodeFactory_SPtr<CoolerOffMessageBusNode> factory)
    : BaseOnOffMessageHandler(logger, factory, COOLER_OFF_MESSAGE_HANDLER_SUBSCRIBER_ID)
{
    logger->set_prefix("CoolerOffMessageHandler");
}

MessageIdType CoolerOffMessageHandler::get_last_message_id() {
    return m_bus_node->get_last_message_id();
}

}
}
}
