/*
 * ADCInvalidChannelException.h
 *
 *  Created on: 19 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_COMMON_EXCEPTIONS_ADCCHANNELINVALIDEXCEPTION_H_
#define SRC_COMMON_EXCEPTIONS_ADCCHANNELINVALIDEXCEPTION_H_

#include "ADCException.h"

using namespace std;

namespace Common {
namespace Exceptions {
class ADCChannelInvalidException : public ADCException {
 public:
    ADCChannelInvalidException(const string & message)
            : ADCException(message) {
    }
    ;
    virtual ~ADCChannelInvalidException() = default;
};
}
}

#endif /* SRC_COMMON_EXCEPTIONS_ADCCHANNELINVALIDEXCEPTION_H_ */
