/*
 * IHeatingUnit.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATINGUNIT_H_
#define SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATINGUNIT_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "Hardware/Abstract/Interfaces/IO/ISwitchable.h"
#include "IHeaterLED.h"
#include "IHeater.h"

using namespace Hardware::Abstract::Interfaces::IO;

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Heaters {
class IHeatingUnit : public ISwitchable {
 public:
    virtual ~IHeatingUnit() = default;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Heaters::IHeatingUnit> IHeatingUnit_SPtr;

#endif /* SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_IHEATINGUNIT_H_ */
