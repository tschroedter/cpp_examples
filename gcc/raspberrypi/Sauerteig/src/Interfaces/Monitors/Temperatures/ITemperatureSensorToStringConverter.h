/*
 * ITemperatureSensorToString.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESENSORTOSTRINGCONVERTER_H_
#define INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESENSORTOSTRINGCONVERTER_H_

#include <string>
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensorWithStatistics.h"

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Temperatures {
class ITemperatureSensorToStringConverter {
 public:
    virtual ~ITemperatureSensorToStringConverter() = default;

    virtual std::string convert(celsius value, double percent) const = 0;
    virtual std::string convert(ITemperatureSensorWithStatistics_SPtr sensor) const = 0;
};
}
}
}
}

typedef std::shared_ptr<Sauerteig::Interfaces::Monitors::Temperatures::ITemperatureSensorToStringConverter> ITemperatureSensorToStringConverter_SPtr;

#endif /* INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESENSORTOSTRINGCONVERTER_H_ */
