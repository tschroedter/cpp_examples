/*
 * IHeaterLED.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLERLED_H_
#define HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLERLED_H_

#include <memory>
#include "Hardware/Abstract/Interfaces/IO/IFlashable.h"

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Coolers {
class ICoolerLED : public Hardware::Abstract::Interfaces::IO::IFlashable {
 public:
    virtual ~ICoolerLED() = default;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Coolers::ICoolerLED> ICoolerLED_SPtr;

#endif /* HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLERLED_H_ */
