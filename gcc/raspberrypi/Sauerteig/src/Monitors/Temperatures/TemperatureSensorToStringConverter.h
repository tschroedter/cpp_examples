/*
 * TemperatureSensorToString.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_MONITORS_TEMPERATURES_TEMPERATURESENSORTOSTRINGCONVERTER_H_
#define SRC_MONITORS_TEMPERATURES_TEMPERATURESENSORTOSTRINGCONVERTER_H_

#include <string>
#include "../../Interfaces/Monitors/Temperatures/ITemperatureSensorToStringConverter.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensorWithStatistics.h"

using namespace Sauerteig::Interfaces::Monitors::Temperatures;

namespace Sauerteig {
namespace Monitors {
namespace Temperatures {
class TemperatureSensorToStringConverter : public ITemperatureSensorToStringConverter {
 public:
    TemperatureSensorToStringConverter() = default;
    virtual ~TemperatureSensorToStringConverter() = default;

    std::string convert(ITemperatureSensorWithStatistics_SPtr sensor) const override;
};
}
}
}

#endif /* SRC_MONITORS_TEMPERATURES_TEMPERATURESENSORTOSTRINGCONVERTER_H_ */
