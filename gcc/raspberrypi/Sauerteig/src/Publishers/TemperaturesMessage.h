/*
 * TemperaturesMessage.h
 *
 *  Created on: 16 Jan. 2018
 *      Author: tom
 */

#ifndef PUBLISHERS_TEMPERATURESMESSAGE_H_
#define PUBLISHERS_TEMPERATURESMESSAGE_H_

#include <string.h>
#include "InMemoryBus/Common/BaseMessage.h"
#include "Common/CommonTypes.h"

namespace Sauerteig {
namespace Publishers {

class TemperaturesMessage : public ::InMemoryBus::Common::BaseMessage {
 public:
    TemperaturesMessage() : InMemoryBus::Common::BaseMessage("TemperaturesMessage") {};
    virtual ~TemperaturesMessage() = default;

    celsius inside_average_value = (celsius)0;
    double inside_average_percent_valid = 0.0;
    celsius outside_average_value = (celsius)0;
    double outside_average_percent_valid = 0.0;

    std::string to_string() {
        std::string result =
                "Inside Temperature = " + std::to_string(inside_average_value) + "C, " +
                "Valid = " + std::to_string(inside_average_percent_valid) + "%, " +
                "Outside Temperature = " + std::to_string(outside_average_value) + "C, " +
                "Valid = " + std::to_string(outside_average_percent_valid) + "%";

        return result;
    }
};

}
}

#endif /* PUBLISHERS_TEMPERATURESMESSAGE_H_ */
