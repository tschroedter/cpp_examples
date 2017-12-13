/*
 * IFailedMessageQueueProcessor.h
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDMESSAGEQUEUEPROCESSOR_H_
#define INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDMESSAGEQUEUEPROCESSOR_H_

#include <memory>

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class IFailedMessageQueueProcessor {
 public:
  virtual ~IFailedMessageQueueProcessor() = default;

  virtual void initialize() = 0;
  virtual void stop() = 0;
};

}
}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::Failed::IFailedMessageQueueProcessor> IFailedMessageQueueProcessor_SPtr;

#endif /* INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDMESSAGEQUEUEPROCESSOR_H_ */
