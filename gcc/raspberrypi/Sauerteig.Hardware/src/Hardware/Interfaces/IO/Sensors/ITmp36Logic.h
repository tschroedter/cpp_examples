/*
 * ITmp36Logic.h
 *
 *  Created on: 14 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_INTERFACES_IO_SENSORS_ITMP36LOGIC_H_
#define SRC_HARDWARE_INTERFACES_IO_SENSORS_ITMP36LOGIC_H_

#include <memory>
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Interfaces {
namespace IO {
namespace Sensors {
class ITmp36Logic {
 public:
    virtual ~ITmp36Logic() = default;

    virtual celsius raw_to_celsius(uint raw_value) = 0;
};
}
}
}
}

typedef std::shared_ptr<Hardware::Interfaces::IO::Sensors::ITmp36Logic> ITmp36Logic_SPtr;

#endif /* SRC_HARDWARE_INTERFACES_IO_SENSORS_ITMP36LOGIC_H_ */
