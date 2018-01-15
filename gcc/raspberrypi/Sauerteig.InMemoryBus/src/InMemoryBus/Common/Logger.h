/*
 * Logger.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_COMMON_LOGGER_H_
#define INMEMORYBUS_COMMON_LOGGER_H_

#include <string>
#include <mutex>
#include <iostream>
#include "ILogger.h"
#include "LogLevel.h"

namespace InMemoryBus {
namespace Common {

using namespace std;

class Logger : public ILogger {
 public:
  Logger() = default;
  virtual ~Logger() = default;

  void debug(string message) override;
  void error(string message) override;
  void warn(string message) override;
  void info(string message) override;

  void set_prefix(string prefix) override;

  LogLevel get_log_level() const override;
  void set_log_level(LogLevel level) override;

 protected:
  Logger(std::ostream& out);

 private:
  std::ostream& m_cout = std::cout;
  recursive_mutex m_mutex { };
  LogLevel m_log_level { LogLevel::DEBUG };

  string m_prefix = "";

  string create_timestamp() const;
  string create_header() const;
};

}
}

#endif /* INMEMORYBUS_COMMON_LOGGER_H_ */
