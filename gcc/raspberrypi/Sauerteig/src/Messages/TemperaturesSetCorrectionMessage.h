/*
 * TemperaturesSetCorrectionMessage.h
 *
 *  Created on: 30 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_MESSAGES_TEMPERATURESSETCORRECTIONMESSAGE_H_
#define SRC_MESSAGES_TEMPERATURESSETCORRECTIONMESSAGE_H_

#define TEMPERATURESSETCORRECTION_MESSAGE_TYPE "TemperaturesSetCorrectionMessage"

#include <memory.h>
#include <string.h>
#include "InMemoryBus/Common/BaseMessage.h"
#include "Common/CommonTypes.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace Messages {

class TemperaturesSetCorrectionMessage : public BaseMessage {
 public:
    TemperaturesSetCorrectionMessage()
            : BaseMessage(TEMPERATURESSETCORRECTION_MESSAGE_TYPE) {
    };

    virtual ~TemperaturesSetCorrectionMessage() = default;

    celsius inside_average_value_correction = (celsius) 0;
    celsius outside_average_value_correction = (celsius) 0;

    string to_string() {
        string result =
                "Inside Temperature Correction = "
                + std::to_string(inside_average_value_correction) + "C, "
                + "Outside Temperature = "
                + std::to_string(outside_average_value_correction) + "C";

        return result;
    }

};

}
}

typedef shared_ptr<Sauerteig::Messages::TemperaturesSetCorrectionMessage> TemperaturesSetCorrectionMessage_SPtr;

#endif /* SRC_MESSAGES_TEMPERATURESSETCORRECTIONMESSAGE_H_ */
