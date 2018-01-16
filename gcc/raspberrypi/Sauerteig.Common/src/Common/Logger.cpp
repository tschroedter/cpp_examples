/*
 * Logger.cpp
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#include "Logger.h"

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <atomic>
#include "Logger.h"
#include "LogLevel.h"

namespace Common {

using namespace std;

Logger::Logger(std::ostream& out)
    : m_cout(out) {
}

void Logger::debug(string message) {
  if (LogLevel::DEBUG <= m_log_level.getEnum()) {
    m_cout << create_header() << "[DEBUG] " << message << endl;
  }
}

void Logger::error(string message) {
  m_cout << create_header() << "[ERROR] " << message << endl;
}

void Logger::warn(string message) {
  if (LogLevel::WARN <= m_log_level.getEnum()) {
    m_cout << create_header() << "[WARN] " << message << endl;
  }
}

void Logger::info(string message) {
  if (LogLevel::INFO <= m_log_level.getEnum()) {
    m_cout << create_header() << "[INFO] " << message << endl;
  }
}

void Logger::set_prefix(string prefix) {
  m_prefix = prefix;
}

string Logger::create_header() const {
  stringstream ss { };

  ss << create_timestamp();

  if (m_prefix.length() > 0) {
    ss << " [" << m_prefix << "] ";
  }

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
