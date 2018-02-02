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
#include "../Interfaces/Publishers/ITemperaturesPublisherSettings.h"

using namespace std;
using namespace Common::Exceptions;
using namespace InMemoryBus::Common;
using namespace Sauerteig::Publishers::Messages;

namespace Sauerteig {
namespace Publishers {

TemperaturesSetCorrectionMessageBusNode::TemperaturesSetCorrectionMessageBusNode(
        ILogger_SPtr logger,
        IBus_SPtr bus,
        string subscriber_id,
        ITemperaturesPublisherSettings_SPtr settings)
        : BusNode(bus, subscriber_id, MESSAGE_TYPE),
          m_logger(logger),
          m_settings(settings){
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageBusNode because 'logger' is null!", "logger");
    }

    if (bus == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageBusNode because 'bus' is null!", "bus");
    }

    if (subscriber_id.length() == 0) {
        throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageBusNode because 'subscriber_id' is empty!",
                                       "subscriber_id");
    }

    if (m_settings == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageBusNode because 'settings' is null!", "settings");
    }

    m_logger->set_prefix("TemperaturesSetCorrectionMessageBusNode");
}

void TemperaturesSetCorrectionMessageBusNode::onNotify(BaseMessage_SPtr p_base_message) {
    TemperaturesSetCorrectionMessage_SPtr message = std::dynamic_pointer_cast<TemperaturesSetCorrectionMessage>(p_base_message);

    celsius inside = message->inside_average_value_correction;
    celsius outside = message->outside_average_value_correction;

    m_settings->set_inside_average_value_correction(inside);
    m_settings->set_outside_average_value_correction(outside);

    m_logger->info("Updated temperatures corrections!");
}

}
}
