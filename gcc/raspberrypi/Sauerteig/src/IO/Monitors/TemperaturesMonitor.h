/*
 * TemperaturesMonitor.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef IO_MONITORS_TEMPERATURESMONITOR_H_
#define IO_MONITORS_TEMPERATURESMONITOR_H_

#include <thread>
#include <string>
#include "../../Interfaces/IO/Monitors/ITemperaturesMonitor.h"
#include "../../Interfaces/IO/Monitors/ITemperatureSensorToStringConverter.h"
#include "../../Interfaces/IO/Sensors/ITemperatureInside.h"
#include "../../Interfaces/IO/Sensors/ITemperatureOutside.h"

class TemperaturesMonitor : public ITemperaturesMonitor {
 public:
    TemperaturesMonitor(ITemperatureInside_SPtr inside,
                        ITemperatureOutside_SPtr outside,
                        ITemperatureSensorToStringConverter_SPtr converter);
    virtual ~TemperaturesMonitor() = default;

    void operator()() override {
        while (1) {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            print();
        }
    }

    void print() const override;

 private:
    ITemperatureInside_SPtr m_inside;
    ITemperatureOutside_SPtr m_outside;
    ITemperatureSensorToStringConverter_SPtr m_converter;

    std::string create_timestamp() const;
};

#endif /* IO_MONITORS_TEMPERATURESMONITOR_H_ */
