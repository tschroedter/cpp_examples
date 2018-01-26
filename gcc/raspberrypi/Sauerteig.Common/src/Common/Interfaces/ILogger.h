/*
 * ILogger.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_SAUERTEIG_COMMON_ILOGGER_H_
#define SRC_SAUERTEIG_COMMON_ILOGGER_H_

#include <memory>
#include <string>
#include "../LogLevel.h"

using namespace std;

namespace Common {
namespace Interfaces {

class ILogger {
 public:
  virtual ~ILogger() = default;

  virtual void debug(string message) = 0;
  virtual void error(string message) = 0;
  virtual void warn(string message) = 0;
  virtual void info(string message) = 0;

  virtual void set_prefix(string prefix) = 0;

  virtual LogLevel get_log_level() const = 0;
  virtual void set_log_level(LogLevel level) = 0;
};

}
}

typedef shared_ptr<Common::Interfaces::ILogger> ILogger_SPtr;

#endif /* SRC_SAUERTEIG_COMMON_ILOGGER_H_ */
