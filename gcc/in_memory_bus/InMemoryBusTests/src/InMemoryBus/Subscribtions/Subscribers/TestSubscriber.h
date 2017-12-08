/*
 * TestSubscriber.h
 *
 *  Created on: 16Jun.,2017
 *      Author: tom
 */

#ifndef TESTSUBSCRIBER_H_
#define TESTSUBSCRIBER_H_

#include "InMemoryBus/Typedefs.h"

#include "TestMessage.h"

namespace InMemoryBusTests {

class TestSubscriber {
 public:
  TestSubscriber();
  virtual ~TestSubscriber();

  InMemoryBus::SubscriberFunction getNotifyFunc();
  void onNotify(Message_SPtr p_message);

  bool wasCalledOnNotify();
  Message_SPtr m_received_message;

 private:
  Message_SPtr m_no_message_received = std::make_shared<TestMessage>("No Message Received");
};

}

#endif /* TESTSUBSCRIBER_H_ */
