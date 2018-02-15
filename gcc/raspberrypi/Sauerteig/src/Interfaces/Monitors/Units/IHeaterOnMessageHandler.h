/*
 * IHeaterOnMessageHandler.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_IHEATERONMESSAGEHANDLER_H_
#define SRC_INTERFACES_MONITORS_IHEATERONMESSAGEHANDLER_H_

#include <memory>
#include <chrono>
#include "InMemoryBus/Common/BaseMessage.h"

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Units {

class IHeaterOnMessageHandler {
 public:
    virtual ~IHeaterOnMessageHandler() = default;

    virtual MessageIdType get_last_message_id() = 0;
};

}
}
}
}

typedef shared_ptr<Sauerteig::Interfaces::Monitors::Units::IHeaterOnMessageHandler> IHeaterOnMessageHandler_SPtr;

#endif /* SRC_INTERFACES_MONITORS_IHEATERONMESSAGEHANDLER_H_ */
