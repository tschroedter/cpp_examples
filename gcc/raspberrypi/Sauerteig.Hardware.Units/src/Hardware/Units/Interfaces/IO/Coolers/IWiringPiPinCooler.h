/*
 * IWiringPiPinHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_UNITS_INTERFACES_IO_COOLERS_IWIRINGPIPINCOOLER_H_
#define HARDWARE_UNITS_INTERFACES_IO_COOLERS_IWIRINGPIPINCOOLER_H_

#include <memory>
#include "Common/CommonTypes.h"

#include "ICooler.h"

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Coolers {
class IWiringPiPinCooler : public Hardware::Units::Interfaces::IO::Coolers::ICooler {
 public:
    virtual ~IWiringPiPinCooler() = default;

    virtual void initialize(wiringpipin wiring_pi_pin) = 0;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Coolers::IWiringPiPinCooler> IWiringPiPinCooler_SPtr;

#endif /* HARDWARE_UNITS_INTERFACES_IO_COOLERS_IWIRINGPIPINCOOLER_H_ */
