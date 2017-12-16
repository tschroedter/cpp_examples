/*
 * ITemperatureOuside.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_INTERFACES_IO_SENSORS_ITEMPERATUREOUTSIDE_H_
#define SRC_HARDWARE_UNITS_INTERFACES_IO_SENSORS_ITEMPERATUREOUTSIDE_H_

#include <memory>
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensor.h"
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Sensors {
class ITemperatureOutside : public Hardware::Abstract::Interfaces::IO::Sensors::ITemperatureSensor {
 public:
    virtual ~ITemperatureOutside() = default;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Sensors::ITemperatureOutside> ITemperatureOutside_SPtr;

#endif /* SRC_HARDWARE_UNITS_INTERFACES_IO_SENSORS_ITEMPERATUREOUTSIDE_H_ */
