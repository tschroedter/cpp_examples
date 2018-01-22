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
#include "Interfaces/ILogger.h"
#include "LogLevel.h"
#include "Interfaces/IThreadInformationProvider.h"

namespace Common {

class Logger : public ::Common::Interfaces::ILogger {
 public:
  Logger(IThreadInformationProvider_SPtr provider);
  virtual ~Logger() = default;

  void debug(std::string message) override;
  void error(std::string message) override;
  void warn(std::string message) override;
  void info(std::string message) override;

  void set_prefix(std::string prefix) override;

  LogLevel get_log_level() const override;
  void set_log_level(LogLevel level) override;

 protected:
  Logger(IThreadInformationProvider_SPtr provider, std::ostream& out);

 private:
  IThreadInformationProvider_SPtr m_provider = nullptr;

  static LogLevel m_log_level;

  std::ostream& m_cout = std::cout;
  std::recursive_mutex m_mutex { };

  std::string m_prefix = "";

  void write_log_line(std::string debug_level, std::string message) const;
  std::string create_timestamp() const;
  std::string create_log_line(std::string debug_level, std::string message) const;
  std::string create_thread_pid() const;
};

}

#endif /* INMEMORYBUS_COMMON_LOGGER_H_ */
