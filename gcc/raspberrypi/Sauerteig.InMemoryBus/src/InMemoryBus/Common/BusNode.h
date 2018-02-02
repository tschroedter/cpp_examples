/*
 * BusNode.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_COMMON_BUSNODE_H_
#define SRC_INMEMORYBUS_COMMON_BUSNODE_H_

#include <string>
#include <functional>
#include "../IBus.h"

using namespace std;

namespace InMemoryBus {
namespace Common {

class BusNode {
 public:
  BusNode(IBus_SPtr bus, string subscriber_id, string message_type);
  virtual ~BusNode();

  virtual void update();

 protected:
  IBus_SPtr m_bus = nullptr;
  string m_subscriber_id;
  string m_message_type;

  function<void(BaseMessage_SPtr)> get_notify_function();
  void send(BaseMessage_SPtr message);
  virtual void onNotify(BaseMessage_SPtr message);
};

}
}

#endif /* SRC_INMEMORYBUS_COMMON_BUSNODE_H_ */
