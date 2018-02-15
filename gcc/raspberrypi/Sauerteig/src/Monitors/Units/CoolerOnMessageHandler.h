/*
 * CoolerOnMessageHandler.h
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MONITORS_UNITS_COOLERONMESSAGEHANDLER_H_
#define SRC_MONITORS_UNITS_COOLERONMESSAGEHANDLER_H_

#include "BaseOnOffMessageHandler.h"
#include "../../BusNodes/CoolerOnMessageBusNode.h"
#include "../../Interfaces/Monitors/Units/ICoolerOnMessageHandler.h"

#define COOLER_ON_MESSAGE_HANDLER_SUBSCRIBER_ID "CoolerOnMessageHandler"

using namespace std;
using namespace Sauerteig::BusNodes;
using namespace Sauerteig::Interfaces::Monitors::Units;

namespace Sauerteig {
namespace Monitors {
namespace Units {

class CoolerOnMessageHandler : public BaseOnOffMessageHandler<CoolerOnMessageBusNode>, public ICoolerOnMessageHandler {
 public:
    CoolerOnMessageHandler(ILogger_SPtr logger, IMessageBusNodeFactory_SPtr<CoolerOnMessageBusNode> factory);
    virtual ~CoolerOnMessageHandler() = default;

    MessageIdType get_last_message_id() override;
};

}
}
}

#endif /* SRC_MONITORS_UNITS_COOLERONMESSAGEHANDLER_H_ */
