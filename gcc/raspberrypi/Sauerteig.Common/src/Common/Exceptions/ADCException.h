/*
 * AnalogDigitalConverterException.h
 *
 *  Created on: 19 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_COMMON_EXCEPTIONS_ADCEXCEPTION_H_
#define SRC_COMMON_EXCEPTIONS_ADCEXCEPTION_H_

#include <string>
#include <exception>

namespace Common {
namespace Exceptions {
class ADCException : public std::exception {
 public:
    ADCException(const std::string & message)
            : m_message(message) {
    }

    virtual ~ADCException() = default;

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

#endif /* SRC_COMMON_EXCEPTIONS_ADCEXCEPTION_H_ */
