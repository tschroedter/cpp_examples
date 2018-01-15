/*
 * Logger.cpp
 *
 *  Created on: 18 Nov. 2017
 *      Author: tom
 */

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <atomic>
#include "Logger.h"
#include "LogLevel.h"

using namespace Common;

void Logger::debug(std::string message) {
    if (LogLevel::DEBUG <= m_log_level.getEnum()) {
        std::cout << create_header() << message << std::endl;
    }
}

void Logger::error(std::string message) {
    std::cout << create_header() << message << std::endl;
}

void Logger::info(std::string message) {
    if (LogLevel::INFO <= m_log_level.getEnum()) {
        std::cout << create_header() << message << std::endl;
    }
}

void Logger::warn(std::string message) {
    if (LogLevel::WARN <= m_log_level.getEnum()) {
        std::cout << create_header() << message << std::endl;
    }
}

void Logger::set_prefix(std::string prefix) {
    m_prefix = prefix;
}

std::string Logger::create_header() const {
    std::stringstream ss { };

    ss << create_timestamp();

    if (m_prefix.length() > 0) {
        ss << " [" << m_prefix << "] ";
    }

    return ss.str();
}

std::string Logger::create_timestamp() const {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    std::string datetime { std::ctime(&now_time_t) };
    std::string datetime_without_return = datetime.substr(0, datetime.length() - 1);

    std::string text = "[" + datetime_without_return + "]";

    return (text);
}

LogLevel Logger::get_log_level() const {
    return m_log_level;
}

void Logger::set_log_level(LogLevel level) {
    m_mutex.lock();
    m_log_level = level;
    m_mutex.unlock();
}
