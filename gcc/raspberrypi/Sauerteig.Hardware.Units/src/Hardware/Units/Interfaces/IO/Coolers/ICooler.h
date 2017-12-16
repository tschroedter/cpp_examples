/*
 * IHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLER_H_
#define HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLER_H_

#include <memory>
#include "Hardware/Abstract/Interfaces/IO/ISwitchable.h"

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Coolers {
class ICooler : public Hardware::Abstract::Interfaces::IO::ISwitchable {
 public:
    virtual ~ICooler() = default;

};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Coolers::ICooler> ICooler_SPtr;

#endif /* HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLER_H_ */
