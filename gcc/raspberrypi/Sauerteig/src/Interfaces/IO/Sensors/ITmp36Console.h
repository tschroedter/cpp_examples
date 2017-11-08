/*
 * ITmp36Console.h
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#ifndef INTERFACES_IO_SENSORS_ITMP36CONSOLE_H_
#define INTERFACES_IO_SENSORS_ITMP36CONSOLE_H_

#include "./Hardware/Interfaces/IO/Sensors/ITmp36.h"
#include "./Common/CommonTypes.h"

class ITmp36Console {
 public:
    virtual ~ITmp36Console() = default;

    virtual void operator()() = 0;
    virtual void initialize(uint channel, const std::string description) = 0;
    virtual void print() const = 0;
};

typedef std::shared_ptr<ITmp36Console> ITmp36Console_SPtr;

#endif /* INTERFACES_IO_ITMP36CONSOLE_H_ */
