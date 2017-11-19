/*
 * ITemperatureInside.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATUREINSIDE_H_
#define SRC_HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATUREINSIDE_H_

#include "ITemperatureSensor.h"
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace Sensors {
class ITemperatureInside : public ITemperatureSensor {
 public:
    virtual ~ITemperatureInside() = default;
};
}
}
}
}
}

typedef std::shared_ptr<
        Hardware::Abstract::Interfaces::IO::Sensors::ITemperatureInside> ITemperatureInside_SPtr;

#endif /* ISRC_HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATUREINSIDE_H_ */
