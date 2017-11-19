/*
 * ITemperature.h
 *
 *  Created on: 12 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURE_H_
#define SRC_HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURE_H_

#include <memory>
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace Sensors {
class ITemperatureSensor {
 public:
    virtual ~ITemperatureSensor() = default;

    virtual celsius get_value() const = 0;
    virtual bool is_value_valid() const = 0;
    virtual void refresh() = 0;
};
}
}
}
}
}

typedef std::shared_ptr<
        Hardware::Abstract::Interfaces::IO::Sensors::ITemperatureSensor> ITemperatureSensor_SPtr;

#endif /* SRC_HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURE_H_ */
