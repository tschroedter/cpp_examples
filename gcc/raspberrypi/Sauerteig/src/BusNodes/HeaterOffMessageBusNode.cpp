/*
 * HeaterOffMessageBusNode.cpp
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#include <string.h>
#include <memory.h>
#include "HeaterOffMessageBusNode.h"
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

HeaterOffMessageBusNode::HeaterOffMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id)
    : BusNode(bus, subscriber_id, HEATEROFF_MESSAGE_TYPE),
      m_logger(logger),
      m_bus(bus),
      m_subscriber_id(subscriber_id) {
    if (m_logger == nullptr) {
    throw ArgumentInvalidException("Can't create HeaterOffMessageBusNode because 'logger' is null!", "logger");
    }

    if (m_bus == nullptr) {
    throw ArgumentInvalidException("Can't create HeaterOffMessageBusNode because 'bus' is null!", "bus");
    }

    if (subscriber_id.length() == 0) {
    throw ArgumentInvalidException("Can't create HeaterOffMessageBusNode because 'subscriber_id' is empty!",
                                   "subscriber_id");
    }

    m_logger->set_prefix("HeaterOffMessageBusNode");
}


void HeaterOffMessageBusNode::onNotify(BaseMessage_SPtr p_base_message) {
    HeaterOffMessage_SPtr message = dynamic_pointer_cast<HeaterOffMessage>(p_base_message);

    m_mutex.lock();

    m_received = chrono::high_resolution_clock::now().time_since_epoch().count();

    m_mutex.unlock();
}

long HeaterOffMessageBusNode::get_received() {

    m_mutex.lock();

    auto value = m_received;

    m_mutex.unlock();

    return value;
}
}
}
