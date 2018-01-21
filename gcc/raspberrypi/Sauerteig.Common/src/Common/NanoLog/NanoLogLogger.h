/*
 * NanoLogLogger.h
 *
 *  Created on: 20 Jan. 2018
 *      Author: tom
 */

#ifndef COMMON_NANOLOG_NANOLOGLOGGER_H_
#define COMMON_NANOLOG_NANOLOGLOGGER_H_

#include <string.h>
#include "../Interfaces/ILogger.h"

namespace Common {
namespace NanoLog {

class NanoLogLogger : public Interfaces::ILogger {
 public:
    NanoLogLogger();
    virtual ~NanoLogLogger() = default;

    void debug(std::string message) override;
    void error(std::string message) override;
    void warn(std::string message) override;
    void info(std::string message) override;

    void set_prefix(std::string prefix) override;

    LogLevel get_log_level() const override;
    void set_log_level(LogLevel level) override;

 private:
    LogLevel m_loglevel = LogLevel::DEBUG;
    std::string m_prefix;
};

}
}

#endif /* COMMON_NANOLOG_NANOLOGLOGGER_H_ */
