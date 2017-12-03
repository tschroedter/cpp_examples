/*
 * ComponentA.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef COMPONENTA_H_
#define COMPONENTA_H_

#include <memory>
#include "InMemoryBus/BusNode.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/BaseMessage.h"

namespace InMemoryBusExample {

class ComponentA : public InMemoryBus::BusNode {
 public:
  ComponentA(IBus_SPtr bus);
  virtual ~ComponentA() = default;

 protected:
  void onNotify(BaseMessage_SPtr p_base_message) override;
};

} /* namespace InMemoryBus */

typedef std::unique_ptr<InMemoryBusExample::ComponentA> ComponentA_UPtr;

#endif /* COMPONENTA_H_ */
