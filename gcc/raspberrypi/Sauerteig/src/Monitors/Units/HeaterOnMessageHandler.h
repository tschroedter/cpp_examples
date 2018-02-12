/*
 * HeaterOnMessageHandler.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MONITORS_UNITS_HEATERONMESSAGEHANDLER_H_
#define SRC_MONITORS_UNITS_HEATERONMESSAGEHANDLER_H_

#include <memory>
#include <chrono>
#include "Common/Interfaces/ILogger.h"
#include "../../BusNodes/HeaterOnMessageBusNode.h"
#include "../../Interfaces/Factories/IMessageBusNodeFactory.h"
#include "../../Interfaces/Monitors/Units/IHeaterOnMessageHandler.h"

#define HEATER_ON_MESSAGE_HANDLER_SUBSCRIBER_ID "HeaterOnMessageHandler"

using namespace std;
using namespace Sauerteig::BusNodes;
using namespace Sauerteig::Interfaces::Monitors::Units;

namespace Sauerteig {
namespace Monitors {
namespace Units {

class HeaterOnMessageHandler : public IHeaterOnMessageHandler {
 public:
    HeaterOnMessageHandler(ILogger_SPtr logger, IMessageBusNodeFactory_SPtr<HeaterOnMessageBusNode> factory);
    virtual ~HeaterOnMessageHandler() = default;

    chrono::system_clock::time_point get_received() override;

 private:
    ILogger_SPtr m_logger = nullptr;
    HeaterOnMessageBusNode_SPtr m_bus_node = nullptr;
};

}
}
}

#endif /* SRC_MONITORS_UNITS_HEATERONMESSAGEHANDLER_H_ */
