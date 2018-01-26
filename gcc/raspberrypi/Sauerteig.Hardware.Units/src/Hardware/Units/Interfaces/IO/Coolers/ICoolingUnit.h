/*
 * IHeatingUnit.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLINGUNIT_H_
#define SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLINGUNIT_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "Hardware/Abstract/Interfaces/IO/ISwitchable.h"
#include "ICooler.h"
#include "ICoolerLED.h"

using namespace Hardware::Abstract::Interfaces::IO;

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Coolers {
class ICoolingUnit : public ISwitchable {
 public:
    virtual ~ICoolingUnit() = default;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Coolers::ICoolingUnit> ICoolingUnit_SPtr;

#endif /* SRC_HARDWARE_UNITS_INTERFACES_IO_COOLERS_ICOOLINGUNIT_H_ */
