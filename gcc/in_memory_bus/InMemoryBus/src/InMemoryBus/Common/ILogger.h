/*
 * ILogger.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_COMMON_ILOGGER_H_
#define INMEMORYBUS_COMMON_ILOGGER_H_

#include <memory>
#include <string>
#include "LogLevel.h"

namespace InMemoryBus {
namespace Common {

using namespace std;

class ILogger {
 public:
  virtual ~ILogger() = default;

  virtual void debug(string message) = 0;
  virtual void error(string message) = 0;
  virtual void info(string message) = 0;

  virtual void set_prefix(string prefix) = 0;

  virtual LogLevel get_log_level() const = 0;
  virtual void set_log_level(LogLevel level) = 0;
};

}
}

typedef std::shared_ptr<InMemoryBus::Common::ILogger> ILogger_SPtr;

#endif /* INMEMORYBUS_COMMON_ILOGGER_H_ */
