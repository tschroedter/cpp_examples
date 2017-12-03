/*
 * ComponentOther.h
 *
 *  Created on: 22 Aug. 2017
 *      Author: tom
 */

#ifndef COMPONENTOTHERA_H_
#define COMPONENTOTHERA_H_

#include "InMemoryBus/BusNode.h"
#include "InMemoryBus/IBus.h"

namespace InMemoryBusExample {
class ComponentOtherA : public InMemoryBus::BusNode {
 public:
  ComponentOtherA(IBus_SPtr bus);
  virtual ~ComponentOtherA() = default;

  void update();
  void set_range(int start, int stop);

 private:
  int m_start = 0;
  int m_stop = 10;
};

} /* namespace InMemoryBus */

typedef std::unique_ptr<InMemoryBusExample::ComponentOtherA> ComponentOtherA_UPtr;

#endif /* COMPONENTOTHERA_H_ */
