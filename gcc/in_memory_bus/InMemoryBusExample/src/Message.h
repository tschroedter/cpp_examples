/*
 * Message.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include <memory>
#include "InMemoryBus/BaseMessage.h"

using namespace std;

namespace InMemoryBusExample {

class Message : public InMemoryBus::BaseMessage {
 public:
  Message(const string event = "Unknown");
  ~Message();

  string getEvent();
 private:
  string m_MessageEvent;
};

}

typedef shared_ptr<InMemoryBusExample::Message> Message_SPtr;

#endif /* MESSAGE_H_ */
