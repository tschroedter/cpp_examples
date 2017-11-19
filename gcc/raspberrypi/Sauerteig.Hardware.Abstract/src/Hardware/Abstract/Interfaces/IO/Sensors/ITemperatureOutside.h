/*
 * ITemperatureOuside.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATUREOUTSIDE_H_
#define SRC_HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATUREOUTSIDE_H_

#include <memory>
#include "ITemperatureSensor.h"
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace Sensors {
class ITemperatureOutside : public ITemperatureSensor {
 public:
    virtual ~ITemperatureOutside() = default;
};
}
}
}
}
}

typedef std::shared_ptr<
        Hardware::Abstract::Interfaces::IO::Sensors::ITemperatureOutside> ITemperatureOutside_SPtr;

#endif /* SRC_HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATUREOUTSIDE_H_ */
