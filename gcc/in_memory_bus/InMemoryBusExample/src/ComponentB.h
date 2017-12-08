/*
 * ComponentB.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef COMPONENTB_H_
#define COMPONENTB_H_

#include "InMemoryBus/Common/BusNode.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BaseMessage.h"

namespace InMemoryBusExample {

class ComponentB : public InMemoryBus::Common::BusNode {
 public:
  ComponentB(IBus_SPtr bus);
  virtual ~ComponentB() = default;

  void update();

 private:
  void onNotify(BaseMessage_SPtr p_base_message) override;
};

} /* namespace InMemoryBus */

typedef std::unique_ptr<InMemoryBusExample::ComponentB> ComponentB_UPtr;

#endif /* COMPONENTB_H_ */
