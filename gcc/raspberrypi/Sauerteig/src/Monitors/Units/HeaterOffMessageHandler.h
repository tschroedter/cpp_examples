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
#include "Common/Interfaces/ILogger.h"
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

class HeaterOffMessageHandler : public IHeaterOffMessageHandler {
 public:
    HeaterOffMessageHandler(ILogger_SPtr logger, IMessageBusNodeFactory_SPtr<HeaterOffMessageBusNode> factory);
    virtual ~HeaterOffMessageHandler() = default;

    chrono::system_clock::time_point get_received() override;

 private:
    ILogger_SPtr m_logger = nullptr;
    HeaterOffMessageBusNode_SPtr m_bus_node = nullptr;
};

}
}
}

#endif /* SRC_MONITORS_UNITS_HEATEROFFMESSAGEHANDLER_H_ */
