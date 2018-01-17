/*
 * TemperaturesMessageBusNode.cpp
 *
 *  Created on: 17 Jan. 2018
 *      Author: tom
 */

#include <string.h>
#include <memory.h>
#include "TemperaturesMessageBusNode.h"
#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "../../Messages/TemperaturesMessage.h"

namespace Sauerteig {
namespace Monitors {
namespace Temperatures {

TemperaturesMessageBusNode::TemperaturesMessageBusNode(
        ILogger_SPtr logger,
        IBus_SPtr bus,
        std::string subscriber_id)
: InMemoryBus::Common::BusNode(bus, subscriber_id, TEMPERATURESMESSAGE_MESSAGE_TYPE), m_logger(logger), m_bus(bus), m_subscriber_id(subscriber_id) {
    if (m_logger == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMessageBusNode because 'logger' is null!",
                                                           "logger");
    }

    if (m_bus == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMessageBusNode because 'bus' is null!",
                                                           "bus");
    }

    if (subscriber_id.length() == 0) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create TemperaturesMessageBusNode because 'subscriber_id' is null or empty!",
                                                           "subscriber_id");
    }

    m_logger->set_prefix("TemperaturesMessageBusNode");
}

void TemperaturesMessageBusNode::onNotify(BaseMessage_SPtr p_base_message) {
  TemperaturesMessage_SPtr message = std::dynamic_pointer_cast<Messages::TemperaturesMessage>(p_base_message);

  m_mutex.lock();

  m_inside_average_value = message->inside_average_value;
  m_inside_average__percent_valid = message->inside_average_percent_valid;

  m_outside_average_value = message->outside_average_value;
  m_outside_average__percent_valid = message->outside_average_percent_valid;

  m_mutex.unlock();

  m_logger->debug("onNotify(...) called!");
}

celsius TemperaturesMessageBusNode::get_inside_average_value() {
    celsius value;

    m_mutex.lock();
    value = m_inside_average_value;
    m_mutex.unlock();

    return value;
}

celsius TemperaturesMessageBusNode::get_inside_average__percent_valid() {
    celsius value;

    m_mutex.lock();
    value = m_inside_average__percent_valid;
    m_mutex.unlock();

    return value;
}

celsius TemperaturesMessageBusNode::get_outside_average_value() {
    celsius value;

    m_mutex.lock();
    value = m_outside_average_value;
    m_mutex.unlock();

    return value;
}
celsius TemperaturesMessageBusNode::get_outside_average__percent_valid() {
    celsius value;

    m_mutex.lock();
    value = m_outside_average__percent_valid;
    m_mutex.unlock();

    return value;
}

}
}
}

