/*
 * IWiringPiPin.h
 *
 *  Created on: 10 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_INTERFACES_IO_IWIRINGPIPIN_H_
#define SRC_HARDWARE_ABSTRACT_INTERFACES_IO_IWIRINGPIPIN_H_

#include <memory>
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
class IWiringPiPin {
 public:
    virtual ~IWiringPiPin() = default;

    virtual void initialize(uint wiring_pi_pin, uint pin_mode) = 0;
    virtual uint get_pin() const = 0;
    virtual void set_mode(uint mode) = 0;
    virtual uint get_mode() const = 0;
    virtual void high() = 0;
    virtual void low() = 0;
    virtual bool is_high() const = 0;
};
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::IWiringPiPin> IWiringPiPin_SPtr;

#endif /* SRC_HARDWARE_ABSTRACT_INTERFACES_IO_IWIRINGPIPIN_H_ */
