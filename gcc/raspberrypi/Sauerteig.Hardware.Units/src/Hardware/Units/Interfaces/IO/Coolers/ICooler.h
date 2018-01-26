/*
 * IHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLER_H_
#define SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLER_H_

#include <memory>
#include "Hardware/Abstract/Interfaces/IO/ISwitchable.h"

using namespace Hardware::Abstract::Interfaces::IO;

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Coolers {
class ICooler : public ISwitchable {
 public:
    virtual ~ICooler() = default;

};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Coolers::ICooler> ICooler_SPtr;

#endif /* SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLER_H_ */
