/*
 * ITemperatureInside.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_INTERFACES_IO_SENSORS_ITEMPERATUREINSIDE_H_
#define SRC_HARDWARE_UNITS_INTERFACES_IO_SENSORS_ITEMPERATUREINSIDE_H_

#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensor.h"
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Sensors {
class ITemperatureInside : public Hardware::Abstract::Interfaces::IO::Sensors::ITemperatureSensor {
 public:
    virtual ~ITemperatureInside() = default;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Sensors::ITemperatureInside> ITemperatureInside_SPtr;

#endif /* ISRC_HARDWARE_UNITS_INTERFACES_IO_SENSORS_ITEMPERATUREINSIDE_H_ */
