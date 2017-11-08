/*
 * ITemperatureOuside.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef INTERFACES_IO_SENSORS_ITEMPERATUREOUTSIDE_H_
#define INTERFACES_IO_SENSORS_ITEMPERATUREOUTSIDE_H_

#include "./Hardware/Interfaces/IO/Sensors/ITemperatureSensor.h"

class ITemperatureOutside : public ITemperatureSensor {
 public:
    virtual ~ITemperatureOutside() = default;
};

typedef std::shared_ptr<ITemperatureOutside> ITemperatureOutside_SPtr;

#endif /* INTERFACES_IO_SENSORS_ITEMPERATUREOUTSIDE_H_ */
