/*
 * ITemperatureSensorToString.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef INTERFACES_MONITORS_ITEMPERATURESENSORTOSTRINGCONVERTER_H_
#define INTERFACES_MONITORS_ITEMPERATURESENSORTOSTRINGCONVERTER_H_

#include <string>
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensor.h"

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
class ITemperatureSensorToStringConverter {
 public:
    virtual ~ITemperatureSensorToStringConverter() = default;

    virtual std::string convert(ITemperatureSensor_SPtr sensor) const = 0;
};
}
}
}

typedef std::shared_ptr<Sauerteig::Interfaces::Monitors::ITemperatureSensorToStringConverter> ITemperatureSensorToStringConverter_SPtr;

#endif /* INTERFACES_MONITORS_ITEMPERATURESENSORTOSTRINGCONVERTER_H_ */
