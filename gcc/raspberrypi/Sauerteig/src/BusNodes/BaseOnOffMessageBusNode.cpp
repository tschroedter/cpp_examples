/*
 * BaseOnOffMessageBusNode.cpp
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#include <string.h>
#include <memory.h>
#include "BaseOnOffMessageBusNode.h"
#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "../Messages/HeaterOffMessage.h"

using namespace std;
using namespace InMemoryBus::Common;
using namespace Common::Exceptions;
using namespace Sauerteig::Messages;

namespace Sauerteig {
namespace BusNodes {

BaseOnOffMessageBusNode::BaseOnOffMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id, string message_type)
    : BusNode(bus, subscriber_id, message_type),
      m_logger(logger),
      m_bus(bus),
      m_subscriber_id(subscriber_id) {
    if (m_logger == nullptr) {
    throw ArgumentInvalidException("Can't create BaseOnOffMessageBusNode because 'logger' is null!", "logger");
    }

    if (m_bus == nullptr) {
    throw ArgumentInvalidException("Can't create BaseOnOffMessageBusNode because 'bus' is null!", "bus");
    }

    if (subscriber_id.length() == 0) {
    throw ArgumentInvalidException("Can't create BaseOnOffMessageBusNode because 'subscriber_id' is empty!",
                                   "subscriber_id");
    }

    m_logger->set_prefix("BaseOnOffMessageBusNode." + subscriber_id + "." + message_type);
}


void BaseOnOffMessageBusNode::onNotify(BaseMessage_SPtr p_base_message) {
    m_mutex.lock();

    m_last_message_id = p_base_message->get_id();

    m_mutex.unlock();
}

MessageIdType BaseOnOffMessageBusNode::get_last_message_id() {

    m_mutex.lock();

    auto value = m_last_message_id;

    m_mutex.unlock();

    return value;
}

}
}
