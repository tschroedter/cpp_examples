/*
 * IOnOffHandler.h
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_UNITS_IONOFFMESSAGEHANDLER_H_
#define SRC_INTERFACES_MONITORS_UNITS_IONOFFMESSAGEHANDLER_H_

#include "InMemoryBus/Common/BaseMessage.h"

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Units {

class IOnOffMessageHandler {
 public:
    virtual ~IOnOffMessageHandler() = default;

    virtual MessageIdType get_last_message_id() = 0;
};

}
}
}
}

typedef shared_ptr<Sauerteig::Interfaces::Monitors::Units::IOnOffMessageHandler> IOnOffMessageHandler_SPtr;

#endif /* SRC_INTERFACES_MONITORS_UNITS_IONOFFMESSAGEHANDLER_H_ */
