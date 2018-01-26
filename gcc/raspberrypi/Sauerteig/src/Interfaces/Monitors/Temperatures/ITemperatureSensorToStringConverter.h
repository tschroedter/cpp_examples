/*
 * ITemperatureSensorToString.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESENSORTOSTRINGCONVERTER_H_
#define SRC_INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESENSORTOSTRINGCONVERTER_H_

#include <string>
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensorWithStatistics.h"

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Temperatures {
class ITemperatureSensorToStringConverter {
 public:
    virtual ~ITemperatureSensorToStringConverter() = default;

    virtual string convert(celsius value, double percent) const = 0;
    virtual string convert(ITemperatureSensorWithStatistics_SPtr sensor) const = 0;
};
}
}
}
}

typedef shared_ptr<Sauerteig::Interfaces::Monitors::Temperatures::ITemperatureSensorToStringConverter> ITemperatureSensorToStringConverter_SPtr;

#endif /* SRC_INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESENSORTOSTRINGCONVERTER_H_ */
