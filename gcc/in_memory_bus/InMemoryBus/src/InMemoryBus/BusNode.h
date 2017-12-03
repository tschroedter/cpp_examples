/*
 * BusNode.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef BUSNODE_H_
#define BUSNODE_H_

#include "IBus.h"

namespace InMemoryBus {

class BusNode {
 public:
  BusNode(IBus_SPtr bus, std::string subscriber_id, std::string message_type);
  virtual ~BusNode();

  virtual void update();

 protected:
  IBus_SPtr m_bus;
  std::string m_subscriber_id;
  std::string m_message_type;

  std::function<void(BaseMessage_SPtr)> getNotifyFunc();
  void send(BaseMessage_SPtr message);
  virtual void onNotify(BaseMessage_SPtr message);
};

}

#endif /* BUSNODE_H_ */
