/*
 * BaseOnOffMessageHandler.h
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MONITORS_UNITS_BASEONOFFMESSAGEHANDLER_H_
#define SRC_MONITORS_UNITS_BASEONOFFMESSAGEHANDLER_H_

#include <memory>
#include <chrono>
#include <assert.h>
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "../../BusNodes/HeaterOnMessageBusNode.h"
#include "../../Interfaces/Factories/IMessageBusNodeFactory.h"
#include "../../Interfaces/Monitors/Units/IOnOffMessageHandler.h"

using namespace std;
using namespace Sauerteig::BusNodes;
using namespace Common::Exceptions;
using namespace Sauerteig::Interfaces::Monitors::Units;

namespace Sauerteig {
namespace Monitors {
namespace Units {

template<class T>
class BaseOnOffMessageHandler : public IOnOffMessageHandler {
 public:
    virtual ~BaseOnOffMessageHandler() = default;

    BaseOnOffMessageHandler(ILogger_SPtr logger, IMessageBusNodeFactory_SPtr<T> factory, string subscriber_id)
            : m_logger(logger) {
        static_assert(is_base_of<BaseOnOffMessageBusNode, T>::value, "T not derived from BaseOnOffMessageBusNode");

        if (m_logger == nullptr) {
            throw ArgumentInvalidException("Can't create BaseOnOffMessageHandler because 'logger' is null!", "logger");
        }

        if (factory == nullptr) {
            throw ArgumentInvalidException("Can't create BaseOnOffMessageHandler because 'factory' is null!", "factory");
        }

        m_bus_node = factory->create(subscriber_id);

        if (m_bus_node == nullptr) {
            throw ArgumentInvalidException("Can't create BaseOnOffMessageHandler because 'bus_node' is null!",
                                           "bus_node");
        }

        m_logger->set_prefix("BaseOnOffMessageHandler." + subscriber_id);
    }

    MessageIdType get_last_message_id() override {
        return m_bus_node->get_last_message_id();
    }

 protected:
    ILogger_SPtr m_logger = nullptr;
    shared_ptr<T> m_bus_node = nullptr;
};

}
}
}

#endif /* SRC_MONITORS_UNITS_BASEONOFFMESSAGEHANDLER_H_ */
