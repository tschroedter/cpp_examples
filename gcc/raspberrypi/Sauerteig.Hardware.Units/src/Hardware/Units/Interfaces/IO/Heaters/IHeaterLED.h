/*
 * IHeaterLED.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATERLED_H_
#define SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATERLED_H_

#include <memory>
#include "Hardware/Abstract/Interfaces/IO/IFlashable.h"

using namespace Hardware::Abstract::Interfaces::IO;

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Heaters {
class IHeaterLED : public IFlashable {
 public:
    virtual ~IHeaterLED() = default;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Heaters::IHeaterLED> IHeaterLED_SPtr;

#endif /* SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATERLED_H_ */
