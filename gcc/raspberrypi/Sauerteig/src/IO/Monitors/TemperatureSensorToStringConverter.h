/*
 * TemperatureSensorToString.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef IO_MONITORS_TEMPERATURESENSORTOSTRINGCONVERTER_H_
#define IO_MONITORS_TEMPERATURESENSORTOSTRINGCONVERTER_H_

#include <string>
#include "../../Interfaces/IO/Sensors/ITemperatureSensor.h"
#include "../../Interfaces/IO/Monitors/ITemperatureSensorToStringConverter.h"

class TemperatureSensorToStringConverter :
        public ITemperatureSensorToStringConverter {
 public:
    TemperatureSensorToStringConverter() = default;
    virtual ~TemperatureSensorToStringConverter() = default;

    std::string convert(ITemperatureSensor_SPtr sensor) const override;
};

#endif /* IO_SENSORS_TEMPERATURESENSORTOSTRINGCONVERTER_H_ */
