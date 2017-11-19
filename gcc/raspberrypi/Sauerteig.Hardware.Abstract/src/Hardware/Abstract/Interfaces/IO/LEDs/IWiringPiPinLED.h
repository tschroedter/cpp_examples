/*
 * IWiringPiPinLED.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_LEDS_IWIRINGPIPINLED_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_LEDS_IWIRINGPIPINLED_H_

#include "ILED.h"
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace LEDs {
class IWiringPiPinLED : public ILED {
 public:
    virtual ~IWiringPiPinLED() = default;

    virtual void initialize(wiringpipin wiring_pi_pin) = 0;
};
}
}
}
}
}

typedef std::shared_ptr<
        Hardware::Abstract::Interfaces::IO::LEDs::IWiringPiPinLED> IWiringPiPinLED_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_LEDS_IWIRINGPIPINLED_H_ */
