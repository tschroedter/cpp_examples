/*
 * ADCTimeOutException.h
 *
 *  Created on: 19 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_COMMON_EXCEPTIONS_ADCTIMEOUTEXCEPTION_H_
#define SRC_COMMON_EXCEPTIONS_ADCTIMEOUTEXCEPTION_H_

#include "ADCException.h"

namespace Common {
namespace Exceptions {
class ADCTimeOutException : public ADCException {
 public:
    ADCTimeOutException(std::string & message)
            : ADCException(message) {
    }
    virtual ~ADCTimeOutException() = default;
};
}
}

#endif /* SRC_COMMON_EXCEPTIONS_ADCTIMEOUTEXCEPTION_H_ */
