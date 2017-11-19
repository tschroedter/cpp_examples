/*
 * IADCTmp36.h
 *
 *  Created on: 14 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_IADCTMP36_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_IADCTMP36_H_

#include <memory>
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace Sensors {
class IADCTmp36 {
 public:
    virtual ~IADCTmp36() = default;

    virtual void initialize(adcchannel channel) = 0;
    virtual bool is_value_valid() const = 0;
    virtual celsius get_value() const = 0;
    virtual void refresh() = 0;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::Sensors::IADCTmp36> IADCTmp36_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_IADCTMP36_H_ */
