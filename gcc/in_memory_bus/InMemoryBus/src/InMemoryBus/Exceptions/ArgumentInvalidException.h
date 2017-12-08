/*
 * NullReferenceException.h
 *
 *  Created on: 16 Oct. 2017
 *      Author: tom
 */

#ifndef EXCEPTIONS_ARGUMENTINVALIDEXCEPTION_H_
#define EXCEPTIONS_ARGUMENTINVALIDEXCEPTION_H_

#include <iostream>
#include <string>
#include <exception>

namespace InMemoryBus {
namespace Exceptions {

using namespace std;

class ArgumentInvalidException : public exception {
 public:
  ArgumentInvalidException(const string & parameter_name) {
    m_message = create_message("", parameter_name);
  }

  ArgumentInvalidException(const string & error_message, const string & parameter_name) {
    m_message = create_message(error_message, parameter_name);
  }

  virtual ~ArgumentInvalidException() {
  }

  const char* what() const noexcept override
  {
    return (m_message.c_str());
  }

  string get_message() const {
    return (m_message);
  }

 private:
  string m_message;

  string create_message(const string & error_message, const string & parameter_name) const {
    string message = "Parameter '" + parameter_name + "' is invalid!";
    ;

    if (!error_message.empty()) {
      message += " " + error_message;
    }

    return (message);
  }

};
}
}

#endif /* EXCEPTIONS_ARGUMENTINVALIDEXCEPTION_H_ */

