/*
 * ITemperatureSensorWithStatistics.h
 *
 *  Created on: 20 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURESENSORWITHSTATISTICS_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURESENSORWITHSTATISTICS_H_

#include <memory>
#include "ITemperatureSensor.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace Sensors {
class ITemperatureSensorWithStatistics : public Hardware::Abstract::Interfaces::IO::Sensors::ITemperatureSensor {
 public:
    virtual ~ITemperatureSensorWithStatistics() = default;

    virtual void initialize(ITemperatureSensor_SPtr sensor) = 0;
    virtual celsius get_average_value() const = 0;
    virtual double get_average_percent_valid() const = 0;
    virtual void set_number_of_samples(uint number_of_samples) = 0;
    virtual uint get_number_of_samples() const = 0;

};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::Sensors::ITemperatureSensorWithStatistics> ITemperatureSensorWithStatistics_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURESENSORWITHSTATISTICS_H_ */
