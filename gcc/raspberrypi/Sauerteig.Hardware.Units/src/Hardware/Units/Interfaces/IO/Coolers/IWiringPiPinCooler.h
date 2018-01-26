/*
 * IWiringPiPinHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_IWIRINGPIPINCOOLER_H_
#define SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_IWIRINGPIPINCOOLER_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "ICooler.h"

using namespace Hardware::Units::Interfaces::IO::Coolers;

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Coolers {
class IWiringPiPinCooler : public ICooler {
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

#endif /* SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_IWIRINGPIPINCOOLER_H_ */
