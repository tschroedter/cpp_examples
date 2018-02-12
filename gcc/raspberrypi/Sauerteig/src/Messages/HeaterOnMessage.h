/*
 * HeaterOnMessage.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MESSAGES_HEATERONMESSAGE_H_
#define SRC_MESSAGES_HEATERONMESSAGE_H_

#define HEATERON_MESSAGE_TYPE "HeaterOnMessage"

#include <memory.h>
#include <string.h>
#include "InMemoryBus/Common/BaseMessage.h"
#include "Common/CommonTypes.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace Messages {

class HeaterOnMessage : public BaseMessage {
 public:
    HeaterOnMessage(): BaseMessage(HEATERON_MESSAGE_TYPE) {
    };

    virtual ~HeaterOnMessage() = default;

    string to_string() {
        string result = "HeaterOnMessage";

        return result;
    }
};

}
}

typedef shared_ptr<Sauerteig::Messages::HeaterOnMessage> HeaterOnMessage_SPtr;

#endif /* SRC_MESSAGES_HEATERONMESSAGE_H_ */
