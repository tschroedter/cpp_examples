/*
 * IWiringPiPinHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_IWIRINGPIPINHEATER_H_
#define SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_IWIRINGPIPINHEATER_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "IHeater.h"

using namespace Hardware::Units::Interfaces::IO::Heaters;

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Heaters {
class IWiringPiPinHeater : public IHeater {
 public:
    virtual ~IWiringPiPinHeater() = default;

    virtual void initialize(wiringpipin wiring_pi_pin) = 0;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Heaters::IWiringPiPinHeater> IWiringPiPinHeater_SPtr;

#endif /* SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_IWIRINGPIPINHEATER_H_ */
