/*
 * TemperaturesSetCorrectionMessageBusNode.cpp
 *
 *  Created on: 30 Jan. 2018
 *      Author: tom
 */
#include <memory.h>
#include <mutex>
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "TemperaturesSetCorrectionMessageBusNode.h"
#include "Messages/TemperaturesSetCorrectionMessage.h"

using namespace std;
using namespace Common::Exceptions;
using namespace InMemoryBus::Common;
using namespace Sauerteig::Publishers::Messages;

namespace Sauerteig {
namespace Publishers {

TemperaturesSetCorrectionMessageBusNode::TemperaturesSetCorrectionMessageBusNode(
        ILogger_SPtr logger,
        IBus_SPtr bus,
        string subscriber_id)
        : BusNode(bus, subscriber_id, MESSAGE_TYPE),
          m_logger(logger),
          m_bus(bus),
          m_subscriber_id(subscriber_id) {
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageBusNode because 'logger' is null!", "logger");
    }

    if (m_bus == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageBusNode because 'bus' is null!", "bus");
    }

    if (subscriber_id.length() == 0) {
        throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageBusNode because 'subscriber_id' is empty!",
                                       "subscriber_id");
    }

    m_logger->set_prefix("TemperaturesSetCorrectionMessageBusNode");
}

void TemperaturesSetCorrectionMessageBusNode::onNotify(BaseMessage_SPtr p_base_message) {
    TemperaturesSetCorrectionMessage_SPtr message = std::dynamic_pointer_cast<TemperaturesSetCorrectionMessage>(p_base_message);

    m_mutex.lock();

    m_inside_average_value_correction = message->inside_average_value_correction;
    m_outside_average_value_correction = message->outside_average_value_correction;

    m_mutex.unlock();
}

celsius TemperaturesSetCorrectionMessageBusNode::get_inside_average_value_correction() {
    m_mutex.lock();

    celsius value = m_inside_average_value_correction;

    m_mutex.unlock();

    return value;
}

celsius TemperaturesSetCorrectionMessageBusNode::get_outside_average_value_correction() {
    m_mutex.lock();

    celsius value = m_outside_average_value_correction;

    m_mutex.unlock();

    return value;
}

}
}
