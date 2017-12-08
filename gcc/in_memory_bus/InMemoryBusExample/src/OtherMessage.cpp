/*
 * OtherMessage.cpp
 *
 *  Created on: 22 Aug. 2017
 *      Author: tom
 */

#include "OtherMessage.h"
#include "InMemoryBus/Common/BaseMessage.h"

namespace InMemoryBusExample {

OtherMessage::OtherMessage()
    : InMemoryBus::Common::BaseMessage("OtherMessage") {
}

}
