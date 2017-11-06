/*
 * ITemperatureInside.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef INTERFACES_IO_SENSORS_ITEMPERATUREINSIDE_H_
#define INTERFACES_IO_SENSORS_ITEMPERATUREINSIDE_H_

#include "ITemperatureSensor.h"

class ITemperatureInside : public ITemperatureSensor {
 public:
    virtual ~ITemperatureInside() = default;
};

typedef std::shared_ptr<ITemperatureInside> ITemperatureInside_SPtr;

#endif /* INTERFACES_IO_SENSORS_ITEMPERATUREINSIDE_H_ */
