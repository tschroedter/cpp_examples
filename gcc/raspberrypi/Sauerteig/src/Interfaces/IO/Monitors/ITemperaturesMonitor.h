/*
 * ITemperaturesMonitor.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef INTERFACES_IO_MONITORS_ITEMPERATURESMONITOR_H_
#define INTERFACES_IO_MONITORS_ITEMPERATURESMONITOR_H_

class ITemperaturesMonitor {
 public:
    virtual ~ITemperaturesMonitor() = default;

    virtual void operator()() = 0;
    virtual void print() const = 0;
};

typedef std::shared_ptr<ITemperaturesMonitor> ITemperaturesMonitor_SPtr;

#endif /* INTERFACES_IO_MONITORS_ITEMPERATURESMONITOR_H_ */
