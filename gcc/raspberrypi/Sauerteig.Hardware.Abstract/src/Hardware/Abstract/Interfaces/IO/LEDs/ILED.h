/*
 * IIOPin.h
 *
 *  Created on: 8 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ILEDS_ILED_H_
#define SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ILEDS_ILED_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "../ISwitchable.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace LEDs {
class ILED : public Hardware::Abstract::Interfaces::IO::ISwitchable {
 public:
    virtual ~ILED() = default;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::LEDs::ILED> ILED_SPtr;

#endif /* SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ILEDS_H_ */
