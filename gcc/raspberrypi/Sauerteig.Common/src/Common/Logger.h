/*
 * Logger.h
 *
 *  Created on: 18 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_COMMON_LOGGER_H_
#define SRC_COMMON_LOGGER_H_

#include <string>
#include <mutex>
#include "Interfaces/ILogger.h"
#include "LogLevel.h"

namespace Common {
class Logger : public Interfaces::ILogger {
 public:
    Logger() = default;
    virtual ~Logger() = default;

    void debug(std::string message) override;
    void error(std::string message) override;
    void info(std::string message) override;
    void warn(std::string message) override;

    void set_prefix(std::string prefix) override;

    LogLevel get_log_level() const override;
    void set_log_level(LogLevel level) override;

 private:
    std::recursive_mutex m_mutex { };
    LogLevel m_log_level { LogLevel::INFO };

    std::string m_prefix = "";

    std::string create_timestamp() const;
    std::string create_header() const;
};
}

#endif /* SRC_COMMON_LOGGER_H_ */
