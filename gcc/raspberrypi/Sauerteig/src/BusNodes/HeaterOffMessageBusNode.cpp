/*
 * HeaterOffMessageBusNode.cpp
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#include <string.h>
#include "HeaterOffMessageBusNode.h"
#include "BaseOnOffMessageBusNode.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "../Messages/HeaterOffMessage.h"

using namespace std;

namespace Sauerteig {
namespace BusNodes {

HeaterOffMessageBusNode::HeaterOffMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id)
    : BaseOnOffMessageBusNode(logger, bus, subscriber_id, HEATEROFF_MESSAGE_TYPE) {
    m_logger->set_prefix("HeaterOffMessageBusNode");
}

}
}
