/*
 * NanoLogLogger.cpp
 *
 *  Created on: 20 Jan. 2018
 *      Author: tom
 */

#include <string.h>
#include "NanoLog.h"
#include "NanoLogLogger.h"

namespace Common {
namespace NanoLog {

NanoLogLogger::NanoLogLogger()
{
    nanolog::initialize(nanolog::GuaranteedLogger(), "/tmp/", "SauerteigLog", 1);
    nanolog::set_log_level(nanolog::LogLevel::DEBUG);

    m_loglevel = LogLevel::DEBUG;
    m_prefix = std::string{"[]"};
}

void NanoLogLogger::debug(std::string message) {
    message = m_prefix + " " + message;

    LOG_DEBUG << message;
}

void NanoLogLogger::error(std::string message) {
    message = m_prefix + " " + message;

    LOG_CRIT << message;
}

void NanoLogLogger::warn(std::string message) {
    message = m_prefix + " " + message;

    LOG_WARN << message;
}

void NanoLogLogger::info(std::string message) {
    message = m_prefix + " " + message;

    LOG_INFO << message;
}

void NanoLogLogger::set_prefix(std::string prefix) {
    m_prefix = "[" + prefix + "]";
}

LogLevel NanoLogLogger::get_log_level() const {
    // TODO bool is_logged(LogLevel level);
    return (m_loglevel);
}

void NanoLogLogger::set_log_level(LogLevel level) {
    m_loglevel = level;

    switch(level.getValue()) {
        case LogLevel::DEBUG:
            nanolog::set_log_level(nanolog::LogLevel::INFO);
            break;
        case LogLevel::INFO:
            nanolog::set_log_level(nanolog::LogLevel::INFO);
            break;
        case LogLevel::WARN:
            nanolog::set_log_level(nanolog::LogLevel::WARN);
            break;
        case LogLevel::ERROR:
            nanolog::set_log_level(nanolog::LogLevel::CRIT);
            break;
        default:
            break;
    }
}

}
}
