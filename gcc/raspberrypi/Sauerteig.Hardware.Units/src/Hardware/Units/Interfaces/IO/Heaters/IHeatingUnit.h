/*
 * IHeatingUnit.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATINGUNIT_H_
#define HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATINGUNIT_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "Hardware/Abstract/Interfaces/IO/ISwitchable.h"
#include "IHeaterLED.h"
#include "IHeater.h"

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Heaters {
class IHeatingUnit : public Hardware::Abstract::Interfaces::IO::ISwitchable {
 public:
    virtual ~IHeatingUnit() = default;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Heaters::IHeatingUnit> IHeatingUnit_SPtr;

#endif /* HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATINGUNIT_H_ */
