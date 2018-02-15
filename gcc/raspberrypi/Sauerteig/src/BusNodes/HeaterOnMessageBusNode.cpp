/*
 * HeaderOnMessageBusNode.cpp
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */


#include <string.h>
#include "HeaterOnMessageBusNode.h"
#include "BaseOnOffMessageBusNode.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "../Messages/HeaterOnMessage.h"

using namespace std;

namespace Sauerteig {
namespace BusNodes {

HeaterOnMessageBusNode::HeaterOnMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id)
    : BaseOnOffMessageBusNode(logger, bus, subscriber_id, HEATERON_MESSAGE_TYPE) {
    m_logger->set_prefix("HeaderOnMessageBusNode");
}

}
}
