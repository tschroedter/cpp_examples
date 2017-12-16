/*
 * LogLevel.h
 *
 *  Created on: 25 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_COMMON_LOGLEVEL_H_
#define SRC_COMMON_LOGLEVEL_H_

#include <ostream>
#include <string>
#include <algorithm>

namespace Common {

class LogLevel {
 public:
    enum Enum {
        ERROR = 0,
        INFO,
        DEBUG,
        INVALID_LOG_LEVEL
    };

    // Constructors
    LogLevel(void);
    LogLevel(Enum ee);
    explicit LogLevel(const std::string& ss);

    virtual ~LogLevel() = default;

    // Overloaded assignment operators
    LogLevel& operator =(const LogLevel& cc);
    LogLevel& operator =(const std::string& ss);
    LogLevel& operator =(Enum ee);

    // Overloaded comparison operators
    bool operator<(const LogLevel& cc) const;
    bool operator<(Enum ee) const;
    bool operator<=(const LogLevel& cc) const;
    bool operator<=(Enum ee) const;
    bool operator>(const LogLevel& cc) const;
    bool operator>(Enum ee) const;
    bool operator>=(const LogLevel& cc) const;
    bool operator>=(Enum ee) const;
    bool operator==(const LogLevel& cc) const;
    bool operator==(const std::string& ss) const;
    bool operator==(const Enum ee) const;
    bool operator!=(const LogLevel& cc) const;
    bool operator!=(const std::string& ss) const;
    bool operator!=(const Enum ee) const;

    // Accessor functions
    inline std::string getString(void) const;
    inline Enum getEnum(void) const;
    inline int getValue(void) const;

 private:
    // Static functions
    static Enum fromString(std::string ss);
    static std::string toString(Enum ee);
    static int toValue(Enum ee);

    // Data members
    Enum m_enum;
    std::string m_string;
    int m_value;
};

inline std::ostream& operator<<(std::ostream& _os, const LogLevel& _e) {
    _os << _e.getString();
    return _os;
}

inline std::string LogLevel::getString(void) const {
    return m_string;
}

LogLevel::Enum LogLevel::getEnum(void) const {
    return m_enum;
}

int LogLevel::getValue(void) const {
    return m_value;
}

} /* namespace Common */

#endif /* SRC_COMMON_LOGLEVEL_H_ */
