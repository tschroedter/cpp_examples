/*
 * ILogger.h
 *
 *  Created on: 18 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_COMMON_INTERFACES_ILOGGER_H_
#define SRC_COMMON_INTERFACES_ILOGGER_H_

#include <memory>
#include <string>
#include "../LogLevel.h"

namespace Common {
namespace Interfaces {
class ILogger {
 public:
    virtual ~ILogger() = default;

    virtual void debug(std::string message) = 0;
    virtual void error(std::string message) = 0;
    virtual void info(std::string message) = 0;

    virtual void set_prefix(std::string prefix) = 0;

    virtual LogLevel get_log_level() const = 0;  // TODO not nice should be ILogLevel
    virtual void set_log_level(LogLevel level) = 0;
};
}
}

typedef std::shared_ptr<Common::Interfaces::ILogger> ILogger_SPtr;

#endif /* SRC_COMMON_INTERFACES_ILOGGER_H_ */
