/*
 * CoolerOffMessage.h
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MESSAGES_COOLEROFFMESSAGE_H_
#define SRC_MESSAGES_COOLEROFFMESSAGE_H_

#define COOLEROFF_MESSAGE_TYPE "CoolerOffMessage"

#include <memory.h>
#include <string.h>
#include "InMemoryBus/Common/BaseMessage.h"
#include "Common/CommonTypes.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace Messages {

class CoolerOffMessage : public BaseMessage {
 public:
    CoolerOffMessage(): BaseMessage(COOLEROFF_MESSAGE_TYPE) {
    };

    virtual ~CoolerOffMessage() = default;

    string to_string() {
        string result = "CoolerOffMessage";

        return result;
    }
};

}
}

typedef shared_ptr<Sauerteig::Messages::CoolerOffMessage> CoolerOffMessage_SPtr;

#endif /* SRC_MESSAGES_COOLEROFFMESSAGE_H_ */
