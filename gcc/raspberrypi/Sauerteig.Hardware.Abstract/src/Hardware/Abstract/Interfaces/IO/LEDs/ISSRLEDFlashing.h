/*
 * ISSRLEDFlashing.h
 *
 *  Created on: 16 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_LEDS_ISSRLEDFLASHING_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_LEDS_ISSRLEDFLASHING_H_

#include "ISSRLED.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace LEDs {
class ISSRLEDFlashing : public Hardware::Abstract::Interfaces::IO::IFlashable {
 public:
    virtual ~ISSRLEDFlashing() = default;

    virtual void initialize(ssroutputpin pin) = 0;
};
}
}
}
}
}

typedef std::shared_ptr<
        Hardware::Abstract::Interfaces::IO::LEDs::ISSRLEDFlashing> ISSRLEDFlashing_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_LEDS_ISSRLEDFLASHING_H_ */
