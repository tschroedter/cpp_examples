/*
 * MockILogger.h
 *
 *  Created on: 11 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_MOCKS_MOCKILOGGER_H_
#define SRC_INMEMORYBUS_MOCKS_MOCKILOGGER_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/Common/ILogger.h"
#include "InMemoryBus/Common/LogLevel.h"

using namespace std;

namespace InMemoryBusTests {

class MockILogger : public InMemoryBus::Common::ILogger {
 public:
  MOCK_METHOD1(debug, void(string message));
  MOCK_METHOD1(error, void(string message));
  MOCK_METHOD1(warn, void(string message));
  MOCK_METHOD1(info, void(string message));

  MOCK_METHOD1(set_prefix, void(string message));
  MOCK_CONST_METHOD0(get_log_level, InMemoryBus::Common::LogLevel());
  MOCK_METHOD1(set_log_level, void(InMemoryBus::Common::LogLevel level));
};

}

#endif /* SRC_INMEMORYBUS_MOCKS_MOCKILOGGER_H_ */
