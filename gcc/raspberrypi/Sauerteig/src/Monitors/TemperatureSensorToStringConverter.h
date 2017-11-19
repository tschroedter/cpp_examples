/*
 * TemperatureSensorToString.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_MONITORS_TEMPERATURESENSORTOSTRINGCONVERTER_H_
#define SRC_MONITORS_TEMPERATURESENSORTOSTRINGCONVERTER_H_

#include <string>
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensor.h"
#include "../Interfaces/Monitors/ITemperatureSensorToStringConverter.h"

using namespace Sauerteig::Interfaces::Monitors;

namespace Sauerteig {
namespace Monitors {
class TemperatureSensorToStringConverter :
        public ITemperatureSensorToStringConverter {
 public:
    TemperatureSensorToStringConverter() = default;
    virtual ~TemperatureSensorToStringConverter() = default;

    std::string convert(ITemperatureSensor_SPtr sensor) const override;
};
}
}

#endif /* SRC_MONITORS_TEMPERATURESENSORTOSTRINGCONVERTER_H_ */
