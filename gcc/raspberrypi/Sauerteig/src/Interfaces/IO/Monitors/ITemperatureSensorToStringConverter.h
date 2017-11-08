/*
 * ITemperatureSensorToString.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef INTERFACES_IO_MONITORS_ITEMPERATURESENSORTOSTRINGCONVERTER_H_
#define INTERFACES_IO_MONITORS_ITEMPERATURESENSORTOSTRINGCONVERTER_H_

#include <string>
#include "./Hardware/Interfaces/IO/Sensors/ITemperatureSensor.h"

class ITemperatureSensorToStringConverter {
 public:
    virtual ~ITemperatureSensorToStringConverter() = default;

    virtual std::string convert(ITemperatureSensor_SPtr sensor) const = 0;
};

typedef std::shared_ptr<ITemperatureSensorToStringConverter> ITemperatureSensorToStringConverter_SPtr;

#endif /* INTERFACES_IO_SENSORS_ITEMPERATURESENSORTOSTRINGCONVERTER_H_ */
