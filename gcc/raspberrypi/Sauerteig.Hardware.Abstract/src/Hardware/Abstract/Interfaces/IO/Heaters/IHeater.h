/*
 * IHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_HEATERS_IHEATER_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_HEATERS_IHEATER_H_

#include "../ISwitchable.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace Heaters {
class IHeater : public Hardware::Abstract::Interfaces::IO::ISwitchable {
 public:
    virtual ~IHeater() = default;

};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::Heaters::IHeater> IHeater_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_HEATERS_IHEATER_H_ */
