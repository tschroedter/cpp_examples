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

using namespace std;

namespace Common {
namespace Exceptions {
class Tmp36Exception : public exception {
 public:
    Tmp36Exception(const string & message)
            : m_message(message) {
    }

    virtual ~Tmp36Exception() = default;

    const char* what() const noexcept override
    {
        return (m_message.c_str());
    }

    string get_message() const {
        return (m_message);
    }

 private:
    string m_message;
};
}
}

#endif /* SRC_COMMON_EXCEPTIONS_TMP36EXCEPTION_H_ */
