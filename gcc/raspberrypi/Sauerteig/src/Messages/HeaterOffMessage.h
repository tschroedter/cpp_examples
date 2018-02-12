/*
 * HeaterOffMessage.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MESSAGES_HEATEROFFMESSAGE_H_
#define SRC_MESSAGES_HEATEROFFMESSAGE_H_

#define HEATEROFF_MESSAGE_TYPE "HeaterOffMessage"

#include <memory.h>
#include <string.h>
#include "InMemoryBus/Common/BaseMessage.h"
#include "Common/CommonTypes.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace Messages {

class HeaterOffMessage : public BaseMessage {
 public:
    HeaterOffMessage(): BaseMessage(HEATEROFF_MESSAGE_TYPE) {
    };

    virtual ~HeaterOffMessage() = default;

    string to_string() {
        string result = "HeaterOffMessage";

        return result;
    }
};

}
}

typedef shared_ptr<Sauerteig::Messages::HeaterOffMessage> HeaterOffMessage_SPtr;

#endif /* SRC_MESSAGES_HEATEROFFMESSAGE_H_ */
