/*
 * HeaterOffMessageHandler.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MONITORS_UNITS_HEATEROFFMESSAGEHANDLER_H_
#define SRC_MONITORS_UNITS_HEATEROFFMESSAGEHANDLER_H_

#include <memory>
#include <chrono>
#include "BaseOnOffMessageHandler.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "../../BusNodes/HeaterOffMessageBusNode.h"
#include "../../Interfaces/Factories/IMessageBusNodeFactory.h"
#include "../../Interfaces/Monitors/Units/IHeaterOffMessageHandler.h"

#define HEATER_OFF_MESSAGE_HANDLER_SUBSCRIBER_ID "HeaterOffMessageHandler"

using namespace std;
using namespace Sauerteig::BusNodes;
using namespace Sauerteig::Interfaces::Monitors::Units;

namespace Sauerteig {
namespace Monitors {
namespace Units {

class HeaterOffMessageHandler : public BaseOnOffMessageHandler<HeaterOffMessageBusNode>, public IHeaterOffMessageHandler {
 public:
    HeaterOffMessageHandler(ILogger_SPtr logger, IMessageBusNodeFactory_SPtr<HeaterOffMessageBusNode> factory);
    virtual ~HeaterOffMessageHandler() = default;

    MessageIdType get_last_message_id() override;
};

}
}
}

#endif /* SRC_MONITORS_UNITS_HEATEROFFMESSAGEHANDLER_H_ */
