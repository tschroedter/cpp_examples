/*
 * Message.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <memory>
#include <string>
#include "InMemoryBus/BaseMessage.h"

using namespace std;

namespace InMemoryBusTests {

class TestMessage : public InMemoryBus::BaseMessage {
 public:
  TestMessage(const std::string event = "Unknown");
  virtual ~TestMessage();
  std::string getEvent();
 private:
  std::string m_MessageEvent;
};

}

typedef shared_ptr<InMemoryBusTests::TestMessage> Message_SPtr;

#endif /* MESSAGE_H_ */
