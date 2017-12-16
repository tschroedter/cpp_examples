/*
 * IHeaterLED.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATERLED_H_
#define HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATERLED_H_

#include <memory>
#include "Hardware/Abstract/Interfaces/IO/IFlashable.h"

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Heaters {
class IHeaterLED : public Hardware::Abstract::Interfaces::IO::IFlashable {
 public:
    virtual ~IHeaterLED() = default;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Heaters::IHeaterLED> IHeaterLED_SPtr;

#endif /* HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATERLED_H_ */
