/*
 * Tmp36Exception.h
 *
 *  Created on: 19 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_COMMON_EXCEPTIONS_TMP36EXCEPTION_H_
#define SRC_COMMON_EXCEPTIONS_TMP36EXCEPTION_H_

#include <string>
#include <exception>

namespace Common {
namespace Exceptions {
class Tmp36Exception : public std::exception {
 public:
    Tmp36Exception(const std::string & message)
            : m_message(message) {
    }

    virtual ~Tmp36Exception() = default;

    const char* what() const noexcept override
    {
        return (m_message.c_str());
    }

    std::string get_message() const {
        return (m_message);
    }

 private:
    std::string m_message;
};
}
}

#endif /* SRC_COMMON_EXCEPTIONS_TMP36EXCEPTION_H_ */
