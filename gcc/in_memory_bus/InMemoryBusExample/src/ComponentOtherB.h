/*
 * ComponentOtherB.h
 *
 *  Created on: 4 Oct. 2017
 *      Author: tom
 */

#ifndef COMPONENTOTHERB_H_
#define COMPONENTOTHERB_H_

#include "InMemoryBus/BusNode.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/BaseMessage.h"

namespace InMemoryBusExample {

class ComponentOtherB : public InMemoryBus::BusNode {
 public:
  ComponentOtherB(IBus_SPtr bus);
  virtual ~ComponentOtherB();

 protected:
  void onNotify(InMemoryBus::BaseMessage* p_base_message) override;
};

} /* namespace InMemoryBus */

typedef std::unique_ptr<InMemoryBusExample::ComponentOtherB> ComponentOtherB_UPtr;

#endif /* COMPONENTOTHERB_H_ */
