/*
 * LogLevel.cpp
 *
 *  Created on: 25 Nov. 2017
 *      Author: tom
 */

#include "LogLevel.h"

namespace Common {

#include <stdexcept>

// Constructors
LogLevel::LogLevel(void)
        : m_enum(ERROR),
          m_string("ERROR"),
          m_value(0) {
}

LogLevel::LogLevel(Enum _e)
        : m_enum(_e),
          m_string(toString(_e)),
          m_value(0) {
}

LogLevel::LogLevel(const std::string& _s)
        : m_enum(fromString(_s)),
          m_string(_s),
          m_value(toValue(m_enum)) {
}

// Assignment operators

LogLevel& LogLevel::operator=(const LogLevel& _c) {
    m_string = _c.m_string;
    m_enum = _c.m_enum;
    m_value = _c.m_value;
    return *this;
}

LogLevel& LogLevel::operator=(const std::string& _s) {
    m_string = _s;
    m_enum = fromString(_s);
    m_value = toValue(m_enum);
    return *this;
}

LogLevel& LogLevel::operator=(Enum _e) {
    m_enum = _e;
    m_string = toString(_e);
    m_value = toValue(_e);
    return *this;
}

bool LogLevel::operator<(const LogLevel& _c) const {
    return (m_value < _c.m_value);
}

bool LogLevel::operator<(Enum _e) const {
    return (m_value < toValue(_e));
}

bool LogLevel::operator<=(const LogLevel& _c) const {
    return (m_value <= _c.m_value);
}

bool LogLevel::operator<=(Enum _e) const {
    return (m_value <= toValue(_e));
}

bool LogLevel::operator>(const LogLevel& _c) const {
    return (m_value > _c.m_value);
}

bool LogLevel::operator>(Enum _e) const {
    return (m_value > toValue(_e));
}

bool LogLevel::operator>=(const LogLevel& _c) const {
    return (m_value >= _c.m_value);
}

bool LogLevel::operator>=(Enum _e) const {
    return (m_value >= toValue(_e));
}

bool LogLevel::operator==(const LogLevel& _c) const {
    return (m_enum == _c.m_enum);
}

bool LogLevel::operator==(const std::string& _s) const {
    return (m_string == _s);
}

bool LogLevel::operator==(const Enum _e) const {
    return (m_enum == _e);
}

bool LogLevel::operator!=(const LogLevel& _c) const {
    return (m_enum != _c.m_enum);
}

bool LogLevel::operator!=(const std::string& _s) const {
    return (m_string != _s);
}

bool LogLevel::operator!=(const Enum _e) const {
    return (m_enum != _e);
}

LogLevel::Enum LogLevel::fromString(std::string _s) {
    // Case insensitive - make all upper case
    transform(_s.begin(), _s.end(), _s.begin(), toupper);
    if (_s == "ERROR")
        return ERROR;
    else if (_s == "INFO")
        return INFO;
    else if (_s == "DEBUG")
        return DEBUG;

    throw std::range_error("Not a valid LogLevel value: " + _s);
    return INVALID_LOG_LEVEL;
}
;

std::string LogLevel::toString(LogLevel::Enum _e) {
    switch (_e) {
        case ERROR: {
            return "ERROR";
        }
        case INFO: {
            return "INFO";
        }
        case DEBUG: {
            return "DEBUG";
        }
        default: {
            return "INVALID_LOG_LEVEL";
        }
    }
    return "Invalid Log Level";
}

int LogLevel::toValue(LogLevel::Enum _e) {
    switch (_e) {
        case ERROR: {
            return 0;
        }
        case INFO: {
            return 1;
        }
        case DEBUG: {
            return 2;
        }
        default: {
            return 3;
        }
    }
    return 3;  // Invalid
}

} /* namespace Common */
