/*
 * CoolerOnMessageBusNode.cpp
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#include <string.h>
#include <memory.h>
#include "CoolerOnMessageBusNode.h"
#include "BaseOnOffMessageBusNode.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "../Messages/CoolerOffMessage.h"

using namespace std;

namespace Sauerteig {
namespace BusNodes {

CoolerOnMessageBusNode::CoolerOnMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id)
    : BaseOnOffMessageBusNode(logger, bus, subscriber_id, COOLEROFF_MESSAGE_TYPE) {
    m_logger->set_prefix("CoolerOnMessageBusNode");
}

}
}

