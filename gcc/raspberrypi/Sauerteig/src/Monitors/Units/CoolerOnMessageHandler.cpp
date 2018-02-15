/*
 * CoolerOnMessageHandler.cpp
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#include "CoolerOnMessageHandler.h"
#include "BaseOnOffMessageHandler.h"
#include "../../BusNodes/CoolerOnMessageBusNode.h"
#include "InMemoryBus/Common/BaseMessage.h"

using namespace std;
using namespace Sauerteig::BusNodes;

namespace Sauerteig {
namespace Monitors {
namespace Units {

CoolerOnMessageHandler::CoolerOnMessageHandler(ILogger_SPtr logger, IMessageBusNodeFactory_SPtr<CoolerOnMessageBusNode> factory)
    : BaseOnOffMessageHandler(logger, factory, COOLER_ON_MESSAGE_HANDLER_SUBSCRIBER_ID)
{
    logger->set_prefix("CoolerOnMessageHandler");
}

MessageIdType CoolerOnMessageHandler::get_last_message_id() {
    return m_bus_node->get_last_message_id();
}

}
}
}
