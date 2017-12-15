/*
 * MockISubscriberInformationEntityFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKS_MOCKISUBSCRIBERINFORMATIONENTITYFACTORY_H_
#define INMEMORYBUS_MOCKS_MOCKISUBSCRIBERINFORMATIONENTITYFACTORY_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "InMemoryBus/Common/SubscriberFunction.h"
#include "InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationEntityFactory.h"

namespace InMemoryBusTests {
class MockISubscriberInformationEntityFactory :
    public InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationEntityFactory {
 public:
  virtual ~MockISubscriberInformationEntityFactory() = default;

  MOCK_METHOD3(create, ISubscriberInformationEntity_SPtr(const std::string, const std::string, const InMemoryBus::Common::SubscriberFunction ));};
}

#endif /* INMEMORYBUS_MOCKS_MOCKISUBSCRIBERINFORMATIONENTITYFACTORY_H_ */
