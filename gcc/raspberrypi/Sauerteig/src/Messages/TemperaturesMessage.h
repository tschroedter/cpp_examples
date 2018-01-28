/*
 * TemperaturesMessage.h
 *
 *  Created on: 16 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_PUBLISHERS_TEMPERATURESMESSAGE_H_
#define SRC_PUBLISHERS_TEMPERATURESMESSAGE_H_

#define TEMPERATURESMESSAGE_MESSAGE_TYPE "TemperaturesMessage"

#include <memory.h>
#include <string.h>
#include "InMemoryBus/Common/BaseMessage.h"
#include "Common/CommonTypes.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace Messages {

class TemperaturesMessage : public BaseMessage {
 public:
    TemperaturesMessage()
            : BaseMessage(TEMPERATURESMESSAGE_MESSAGE_TYPE) {
    }
    ;
    virtual ~TemperaturesMessage() = default;

    celsius inside_average_value = (celsius) 0;
    double inside_average_percent_valid = 0.0;
    celsius outside_average_value = (celsius) 0;
    double outside_average_percent_valid = 0.0;

    string to_string() {
        string result = "Inside Temperature = " + std::to_string(inside_average_value) + "C, " + "Valid = "
                + std::to_string(inside_average_percent_valid) + "%, " + "Outside Temperature = "
                + std::to_string(outside_average_value) + "C, " + "Valid = "
                + std::to_string(outside_average_percent_valid) + "%";

        return result;
    }
};

}
}

typedef shared_ptr<Sauerteig::Messages::TemperaturesMessage> TemperaturesMessage_SPtr;

#endif /* SRC_PUBLISHERS_TEMPERATURESMESSAGE_H_ */
