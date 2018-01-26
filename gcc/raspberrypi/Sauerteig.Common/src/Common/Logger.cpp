/*
 * Logger.cpp
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#include "Logger.h"

#include <thread>
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <atomic>
#include "Logger.h"
#include "LogLevel.h"
#include "Exceptions/ArgumentInvalidExceptions.h"
#include "Interfaces/IThreadInformationProvider.h"

using namespace Common::Exceptions;

namespace Common {

LogLevel Logger::m_log_level = LogLevel::DEBUG;

using namespace std;

Logger::Logger(IThreadInformationProvider_SPtr provider)
: m_provider(provider) {
    if (m_provider == nullptr) {
        throw ArgumentInvalidException("Can't create Logger because 'provider' is null!",
                                                           "provider");
    }
}

Logger::Logger(IThreadInformationProvider_SPtr provider, std::ostream& out)
    : m_provider(provider),
      m_cout(out) {
    if (m_provider == nullptr) {
        throw ArgumentInvalidException("Can't create Logger because 'provider' is null!",
                                                           "provider");
    }

    if (m_cout == nullptr) {
        throw ArgumentInvalidException("Can't create Logger because 'out' is null!",
                                                           "out");
    }
}

void Logger::debug(string message) {
  if (LogLevel::DEBUG <= m_log_level.getEnum()) {
      write_log_line("[DEBUG]", message);
  }
}

void Logger::error(string message) {
    write_log_line("[ERROR]", message);
}

void Logger::warn(string message) {
  if (LogLevel::WARN <= m_log_level.getEnum()) {
      write_log_line("[WARN] ", message);
  }
}

void Logger::info(string message) {
  if (LogLevel::INFO <= m_log_level.getEnum()) {
      write_log_line("[INFO] ", message);
  }
}

void Logger::set_prefix(string prefix) {
  m_prefix = prefix;
}

void Logger::write_log_line(string debug_level, string message) const {
    string line = create_log_line(debug_level, message);

    m_cout << line << endl;
}

string Logger::create_log_line(string debug_level, string message) const {
  stringstream ss { };

  ss << create_timestamp();

  ss << " " << debug_level;

  if (m_prefix.length() > 0) {
    ss << " [" << m_prefix << "]";
  }

  ss << " " << message;

  return (ss.str());
}

string Logger::create_timestamp() const {
  auto now = chrono::system_clock::now();
  time_t now_time_t = chrono::system_clock::to_time_t(now);

  string datetime { ctime(&now_time_t) };
  string datetime_without_return = datetime.substr(0, datetime.length() - 1);

  string text = "[" + datetime_without_return + "]";

  return (text);
}

LogLevel Logger::get_log_level() const {
  return (m_log_level);
}

void Logger::set_log_level(LogLevel level) {
  std::lock_guard<std::recursive_mutex> lock(m_mutex);

  m_log_level = level;
}

}
