/*
 * ITemperatureSensor.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_INTERFACES_IO_SENSORS_ITEMPERATURESENSOR_H_
#define HARDWARE_INTERFACES_IO_SENSORS_ITEMPERATURESENSOR_H_

#include <memory>
#include "./Common/CommonTypes.h"

class ITemperatureSensor {
 public:
    virtual ~ITemperatureSensor() = default;

    virtual void initialize(uint channel) = 0;
    virtual bool is_value_valid() const = 0;
    virtual uint get_value() const = 0;
    virtual uint get_value_raw() const = 0;
    virtual void refresh() = 0;
};

typedef std::shared_ptr<ITemperatureSensor> ITemperatureSensor_SPtr;

#endif /* INTERFACES_IO_SENSORS_ITEMPERATURESENSOR_H_ */
