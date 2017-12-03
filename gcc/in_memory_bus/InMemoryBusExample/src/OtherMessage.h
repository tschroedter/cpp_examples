/*
 * OtherMessage.h
 *
 *  Created on: 22 Aug. 2017
 *      Author: tom
 */

#ifndef OTHERMESSAGE_H_
#define OTHERMESSAGE_H_

#include <memory>
#include "InMemoryBus/BaseMessage.h"

using namespace std;

namespace InMemoryBusExample {
class OtherMessage : public InMemoryBus::BaseMessage {
 public:
  OtherMessage();
  virtual ~OtherMessage() = default;

  int counter = 0;
};

}

typedef shared_ptr<InMemoryBusExample::OtherMessage> OtherMessage_SPtr;

#endif /* OTHERMESSAGE_H_ */
