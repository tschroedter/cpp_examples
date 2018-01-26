/*
 * IMessageBusNotifier.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORY_NOTIFIERS_IMESSAGEBUSNOTIFIER_H_
#define SRC_INMEMORY_NOTIFIERS_IMESSAGEBUSNOTIFIER_H_

#include <memory>

namespace InMemoryBus {
namespace Notifiers {
class IMessageBusNotifier {
 public:
  virtual ~IMessageBusNotifier() = default;

  virtual void operator()() = 0;
  virtual void notify() = 0;
};
}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::IMessageBusNotifier> IMessageBusNotifier_SPtr;

#endif /* SRC_INMEMORY_NOTIFIERS_IMESSAGEBUSNOTIFIER_H_ */
