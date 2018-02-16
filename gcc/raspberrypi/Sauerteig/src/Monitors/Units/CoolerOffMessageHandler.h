/*
 * CoolerOffMessageHandler.h
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MONITORS_UNITS_COOLEROFFMESSAGEHANDLER_H_
#define SRC_MONITORS_UNITS_COOLEROFFMESSAGEHANDLER_H_

#include "BaseOnOffMessageHandler.h"
#include "../../BusNodes/CoolerOffMessageBusNode.h"
#include "../../Interfaces/Monitors/Units/ICoolerOffMessageHandler.h"

#define COOLER_OFF_MESSAGE_HANDLER_SUBSCRIBER_ID "CoolerOffMessageHandler"

using namespace std;
using namespace Sauerteig::Interfaces::Monitors::Units;

namespace Sauerteig {
namespace Monitors {
namespace Units {

class CoolerOffMessageHandler : public BaseOnOffMessageHandler<CoolerOffMessageBusNode>, public ICoolerOffMessageHandler {
 public:
    CoolerOffMessageHandler(ILogger_SPtr logger, IMessageBusNodeFactory_SPtr<CoolerOffMessageBusNode> factory);
    virtual ~CoolerOffMessageHandler() = default;

    MessageIdType get_last_message_id() override;
};

}
}
}


#endif /* SRC_MONITORS_UNITS_COOLEROFFMESSAGEHANDLER_H_ */
