/*
 * ArgumentInvalidExceptions.h
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#ifndef SAUERTEIG_EXCEPTIONS_ARGUMENTINVALIDEXCEPTIONS_H_
#define SAUERTEIG_EXCEPTIONS_ARGUMENTINVALIDEXCEPTIONS_H_

#include <iostream>
#include <string>
#include <exception>

namespace Common {
namespace Exceptions {
class ArgumentInvalidException : public std::exception {
 public:
    ArgumentInvalidException(const std::string & parameter_name) {
        m_message = create_message("", parameter_name);
    }

    ArgumentInvalidException(const std::string & error_message,
                             const std::string & parameter_name) {
        m_message = create_message(error_message, parameter_name);
    }

    virtual ~ArgumentInvalidException() {
    }

    const char* what() const noexcept override
    {
        return (m_message.c_str());
    }

    std::string get_message() const {
        return (m_message);
    }

 private:
    std::string m_message;

    std::string create_message(const std::string & error_message,
                               const std::string & parameter_name) const {
        std::string message = "Parameter '" + parameter_name + "' is invalid!";
        ;

        if (!error_message.empty()) {
            message += " " + error_message;
        }

        return (message);
    }

};
}
}

#endif /* EXCEPTIONS_ARGUMENTINVALIDEXCEPTIONS_H_ */