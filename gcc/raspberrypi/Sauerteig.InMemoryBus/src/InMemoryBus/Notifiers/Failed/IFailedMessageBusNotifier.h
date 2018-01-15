/*
 * IFailedMessageBusNotifier.h
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDMESSAGEBUSNOTIFIER_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDMESSAGEBUSNOTIFIER_H_

#include <memory>

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class IFailedMessageBusNotifier {
 public:
  virtual ~IFailedMessageBusNotifier() = default;

  virtual void operator()() = 0;
  virtual void notify() = 0;
};

}
}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::Failed::IFailedMessageBusNotifier> IFailedMessageBusNotifier_SPtr;

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDMESSAGEBUSNOTIFIER_H_ */
