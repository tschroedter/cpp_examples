/*
 * IHeaterLED.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLERLED_H_
#define SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLERLED_H_

#include <memory>
#include "Hardware/Abstract/Interfaces/IO/IFlashable.h"

using namespace Hardware::Abstract::Interfaces::IO;

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Coolers {
class ICoolerLED : public IFlashable {
 public:
    virtual ~ICoolerLED() = default;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Coolers::ICoolerLED> ICoolerLED_SPtr;

#endif /* SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLERLED_H_ */
