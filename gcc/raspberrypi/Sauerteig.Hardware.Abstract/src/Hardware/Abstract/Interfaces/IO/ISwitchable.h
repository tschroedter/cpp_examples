/*
 * ISwitchable.h
 *
 *  Created on: 10 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ISWITCHABLE_H_
#define SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ISWITCHABLE_H_

#include <memory>
#include "IWiringPiPin.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
class ISwitchable {
 public:
    virtual ~ISwitchable() = default;

    virtual void on() = 0;
    virtual void off() = 0;
    virtual bool is_on() const = 0;
};
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::ISwitchable> ISwitchable_SPtr;

#endif /* SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ISWITCHABLE_H_ */
