/*
 * ISubscibersNotifierFactory.h
 *
 *  Created on: 16 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_ISUBSCIBERSNOTIFIERFACTORY_H_
#define INMEMORYBUS_NOTIFIERS_ISUBSCIBERSNOTIFIERFACTORY_H_

#include <memory>
#include "ISubscibersNotifier.h"

namespace InMemoryBus {
namespace Notifiers {

class ISubscibersNotifierFactory {
 public:
  virtual ~ISubscibersNotifierFactory() = default;

  virtual ISubscibersNotifier_SPtr create() = 0;
};

}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::ISubscibersNotifierFactory> ISubscibersNotifierFactory_SPtr;

#endif /* INMEMORYBUS_NOTIFIERS_ISUBSCIBERSNOTIFIERFACTORY_H_ */
