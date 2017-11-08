/*
 * ITmp36.h
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_INTERFACES_IO_SENSORS_ITMP36_H_
#define HARDWARE_INTERFACES_IO_SENSORS_ITMP36_H_

#include <memory>
#include "ITemperatureSensor.h"

class ITmp36 : public ITemperatureSensor {
 public:
    virtual ~ITmp36() = default;
};

typedef std::shared_ptr<ITmp36> ITmp36_SPtr;

#endif /* INTERFACES_IO_ITMP36_H_ */
