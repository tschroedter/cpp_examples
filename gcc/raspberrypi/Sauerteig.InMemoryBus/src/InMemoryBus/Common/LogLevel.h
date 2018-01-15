/*
 * LogLevel.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_COMMON_LOGLEVEL_H_
#define INMEMORYBUS_COMMON_LOGLEVEL_H_

#include <ostream>
#include <string>
#include <algorithm>

namespace InMemoryBus {
namespace Common {

using namespace std;

class LogLevel {
 public:
  enum Enum {
    ERROR = 0,
    WARN,
    INFO,
    DEBUG,
    INVALID_LOG_LEVEL
  };

  // Constructors
  LogLevel(void);
  LogLevel(Enum ee);
  explicit LogLevel(const string& ss);

  virtual ~LogLevel() = default;

  // Overloaded assignment operators
  LogLevel& operator =(const LogLevel& cc);
  LogLevel& operator =(const string& ss);
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
  bool operator==(const string& ss) const;
  bool operator==(const Enum ee) const;
  bool operator!=(const LogLevel& cc) const;
  bool operator!=(const string& ss) const;
  bool operator!=(const Enum ee) const;

  // Accessor functions
  inline string getString(void) const;
  inline Enum getEnum(void) const;
  inline int getValue(void) const;

 private:
  // Static functions
  static Enum fromString(string ss);
  static string toString(Enum ee);
  static int toValue(Enum ee);

  // Data members
  Enum m_enum;
  string m_string;
  int m_value;
};

inline ostream& operator<<(ostream& _os, const LogLevel& _e) {
  _os << _e.getString();
  return _os;
}

inline string LogLevel::getString(void) const {
  return (m_string);
}

LogLevel::Enum LogLevel::getEnum(void) const {
  return (m_enum);
}

int LogLevel::getValue(void) const {
  return (m_value);
}

}
}

#endif /* INMEMORYBUS_COMMON_LOGLEVEL_H_ */
