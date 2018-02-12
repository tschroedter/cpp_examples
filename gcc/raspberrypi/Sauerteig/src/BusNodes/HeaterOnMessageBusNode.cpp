/*
 * HeaderOnMessageBusNode.cpp
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */


#include <string.h>
#include <memory.h>
#include "HeaterOnMessageBusNode.h"
#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "../Messages/HeaterOnMessage.h"

using namespace std;
using namespace InMemoryBus::Common;
using namespace Common::Exceptions;
using namespace Sauerteig::Messages;

namespace Sauerteig {
namespace BusNodes {

HeaterOnMessageBusNode::HeaterOnMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id)
    : BusNode(bus, subscriber_id, HEATERON_MESSAGE_TYPE),
      m_logger(logger),
      m_bus(bus),
      m_subscriber_id(subscriber_id) {
    if (m_logger == nullptr) {
    throw ArgumentInvalidException("Can't create HeaderOnMessageBusNode because 'logger' is null!", "logger");
    }

    if (m_bus == nullptr) {
    throw ArgumentInvalidException("Can't create HeaderOnMessageBusNode because 'bus' is null!", "bus");
    }

    if (subscriber_id.length() == 0) {
    throw ArgumentInvalidException("Can't create HeaderOnMessageBusNode because 'subscriber_id' is empty!",
                                   "subscriber_id");
    }

    m_logger->set_prefix("HeaderOnMessageBusNode");
}


void HeaterOnMessageBusNode::onNotify(BaseMessage_SPtr p_base_message) {
    HeaterOnMessage_SPtr message = dynamic_pointer_cast<HeaterOnMessage>(p_base_message);

    m_mutex.lock();

    m_received = chrono::system_clock::now();

    m_mutex.unlock();
}

chrono::system_clock::time_point HeaterOnMessageBusNode::get_received() {

    m_mutex.lock();

    auto value = m_received;

    m_mutex.unlock();

    return value;
}
}
}