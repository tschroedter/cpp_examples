/*
 * TemperaturesMonitor.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_MONITORS_TEMPERATURESMONITOR_H_
#define SRC_MONITORS_TEMPERATURESMONITOR_H_

#include <thread>
#include <string>
#include "Common/Interfaces/ILogger.h"
#include "../Interfaces/Monitors/ITemperaturesMonitor.h"
#include "../Interfaces/Monitors/ITemperatureSensorToStringConverter.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureInside.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureOutside.h"

using namespace Sauerteig::Interfaces::Monitors;

namespace Sauerteig {
namespace Monitors {
class TemperaturesMonitor : public ITemperaturesMonitor {
 public:
    TemperaturesMonitor(ILogger_SPtr logger, ITemperatureInside_SPtr inside,
                        ITemperatureOutside_SPtr outside,
                        ITemperatureSensorToStringConverter_SPtr converter);
    virtual ~TemperaturesMonitor() = default;

    void operator()() override {
        while (1) {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            m_logger->info(to_string());
        }
    }

    std::string to_string() const override;

 private:
    ILogger_SPtr m_logger;
    ITemperatureInside_SPtr m_inside;
    ITemperatureOutside_SPtr m_outside;
    ITemperatureSensorToStringConverter_SPtr m_converter;

    std::string create_timestamp() const;
};
}
}

#endif /* SRC_MONITORS_TEMPERATURESMONITOR_H_ */
