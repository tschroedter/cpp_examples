/*
 * SubscibersNotifierFactory.h
 *
 *  Created on: 16 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FACTORIES_SUBSCIBERSNOTIFIERFACTORY_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FACTORIES_SUBSCIBERSNOTIFIERFACTORY_H_

#include "Common/Interfaces/ILogger.h"
#include "ISubscibersNotifierFactory.h"
#include "../ISubscibersNotifier.h"
#include "../Failed/IFailedToNotifyManager.h"
#include "../../Subscribtions/ISubscribtionManager.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Factories {

class SubscibersNotifierFactory : public ISubscibersNotifierFactory {
 public:
  SubscibersNotifierFactory(ILogger_SPtr logger, ISubscribtionManager_SPtr manager,
                            IFailedToNotifyManager_SPtr failed_manager);
  virtual ~SubscibersNotifierFactory() = default;

  ISubscibersNotifier_SPtr create() override;

 private:
  ILogger_SPtr m_logger = nullptr;
  ISubscribtionManager_SPtr m_manager = nullptr;
  IFailedToNotifyManager_SPtr m_failed_manager = nullptr;
};

}
}
}

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FACTORIES_SUBSCIBERSNOTIFIERFACTORY_H_ */
