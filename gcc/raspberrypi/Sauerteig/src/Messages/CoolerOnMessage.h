/*
 * CoolerOnMessage.h
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MESSAGES_COOLERONMESSAGE_H_
#define SRC_MESSAGES_COOLERONMESSAGE_H_

#define COOLERON_MESSAGE_TYPE "CoolerOnMessage"

#include <memory.h>
#include <string.h>
#include "InMemoryBus/Common/BaseMessage.h"
#include "Common/CommonTypes.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace Messages {

class CoolerOnMessage : public BaseMessage {
 public:
    CoolerOnMessage(): BaseMessage(COOLERON_MESSAGE_TYPE) {
    };

    virtual ~CoolerOnMessage() = default;

    string to_string() {
        string result = "CoolerOnMessage";

        return result;
    }
};

}
}

typedef shared_ptr<Sauerteig::Messages::CoolerOnMessage> CoolerOnMessage_SPtr;

#endif /* SRC_MESSAGES_COOLERONMESSAGE_H_ */
