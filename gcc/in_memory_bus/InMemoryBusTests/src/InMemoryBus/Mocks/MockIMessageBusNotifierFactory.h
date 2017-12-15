/*
 * MockIMessageBusNotifierFactory.h
 *
 *  Created on: 16 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKS_MOCKIMESSAGEBUSNOTIFIERFACTORY_H_
#define INMEMORYBUS_MOCKS_MOCKIMESSAGEBUSNOTIFIERFACTORY_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "InMemoryBus/Notifiers/Factories/IMessageBusNotifierFactory.h"
#include "InMemoryBus/Notifiers/IMessageBusNotifier.h"

namespace InMemoryBusTests {
class MockIMessageBusNotifierFactory : public InMemoryBus::Notifiers::Factories::IMessageBusNotifierFactory {
 public:
  virtual ~MockIMessageBusNotifierFactory() = default;

  MOCK_METHOD0(create, IMessageBusNotifier_SPtr());};
}

#endif /* INMEMORYBUS_MOCKS_MOCKIMESSAGEBUSNOTIFIERFACTORY_H_ */
