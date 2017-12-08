/*
 * ComponentOtherB.h
 *
 *  Created on: 4 Oct. 2017
 *      Author: tom
 */

#ifndef COMPONENTOTHERB_H_
#define COMPONENTOTHERB_H_

#include <bitset>
#include "InMemoryBus/Common/BusNode.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BaseMessage.h"

#define EXPECTED_NO_OF_MESSAGES 100

using namespace std;

namespace InMemoryBusExample {

class ComponentOtherB : public InMemoryBus::Common::BusNode {
 public:
  ComponentOtherB(IBus_SPtr bus);
  virtual ~ComponentOtherB() = default;

  bool get_status();

 protected:
  void onNotify(BaseMessage_SPtr p_base_message) override;

  bitset<EXPECTED_NO_OF_MESSAGES> m_bitset { 0 };
};

} /* namespace InMemoryBus */

typedef std::unique_ptr<InMemoryBusExample::ComponentOtherB> ComponentOtherB_UPtr;

#endif /* COMPONENTOTHERB_H_ */
