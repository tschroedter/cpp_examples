/*
 * TestLogger.h
 *
 *  Created on: 14 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_COMMON_TESTLOGGER_H_
#define SRC_INMEMORYBUS_COMMON_TESTLOGGER_H_

#include <iostream>
#include <InMemoryBus/Common/Logger.h>

namespace InMemoryBusTests {

class TestLogger : public InMemoryBus::Common::Logger {
 public:
  TestLogger() = default;
  TestLogger(std::ostream& cout);
  virtual ~TestLogger() = default;
};

} /* namespace InMemoryBusTests */

#endif /* SRC_INMEMORYBUS_COMMON_TESTLOGGER_H_ */
