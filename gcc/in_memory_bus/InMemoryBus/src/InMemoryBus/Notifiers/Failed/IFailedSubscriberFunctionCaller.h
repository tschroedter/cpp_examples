/*
 * IFailedSubscriberFunctionCaller.h
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDSUBSCRIBERFUNCTIONCALLER_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDSUBSCRIBERFUNCTIONCALLER_H_

#include "../BaseSubscriberFunctionCaller.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class IFailedSubscriberFunctionCaller : public BaseSubscriberFunctionCaller {
};

}
}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::Failed::IFailedSubscriberFunctionCaller> IFailedSubscriberFunctionCaller_SPtr;

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDSUBSCRIBERFUNCTIONCALLER_H_ */
