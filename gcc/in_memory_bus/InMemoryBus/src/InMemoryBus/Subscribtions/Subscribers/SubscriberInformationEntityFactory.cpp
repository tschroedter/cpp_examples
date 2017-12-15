/*
 * SubscriberInformationEntityFactory.cpp
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#include <memory>
#include <string>
#include "SubscriberInformationEntityFactory.h"
#include "SubscriberInformationEntity.h"
#include "ISubscriberInformationEntity.h"
#include "../../Common/SubscriberFunction.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {

ISubscriberInformationEntity_SPtr SubscriberInformationEntityFactory::create(
    const std::string subscriber_id, const std::string message_type,
    const InMemoryBus::Common::SubscriberFunction subscriber_function) {

  ISubscriberInformationEntity_SPtr information = std::make_shared<SubscriberInformationEntity>(subscriber_id,
                                                                                                message_type,
                                                                                                subscriber_function);

  return information;
}

}
}
}
