/*
 * ISSRLED.h
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_LEDS_ISSRLED_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_LEDS_ISSRLED_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "../ISwitchable.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace LEDs {
class ISSRLED : public Hardware::Abstract::Interfaces::IO::ISwitchable {
 public:
    virtual ~ISSRLED() = default;

    virtual void initialize(ssroutputpin pin) = 0;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::LEDs::ISSRLED> ISSRLED_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_LEDS_ISSRLED_H_ */
