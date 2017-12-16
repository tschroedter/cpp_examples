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
#include "../../Interfaces/Monitors/Temperatures/ITemperaturesMonitor.h"
#include "../../Interfaces/Monitors/Temperatures/ITemperatureSensorToStringConverter.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensorWithStatistics.h"
#include "Hardware/Units/Interfaces/IO/Sensors/ITemperatureInside.h"
#include "Hardware/Units/Interfaces/IO/Sensors/ITemperatureOutside.h"

namespace Sauerteig {
namespace Monitors {
namespace Temperatures {
class TemperaturesMonitor : public Sauerteig::Interfaces::Monitors::Temperatures::ITemperaturesMonitor {
 public:
    // TODO constructor is getting to big
    TemperaturesMonitor(ILogger_SPtr logger, ITemperatureInside_SPtr inside, ITemperatureOutside_SPtr outside,
                        ITemperatureSensorWithStatistics_SPtr inside_with_statistics,
                        ITemperatureSensorWithStatistics_SPtr outside_with_statistics,
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
    ILogger_SPtr m_logger = nullptr;
    ITemperatureSensorWithStatistics_SPtr m_inside = nullptr;
    ITemperatureSensorWithStatistics_SPtr m_outside = nullptr;
    ITemperatureSensorToStringConverter_SPtr m_converter = nullptr;

    std::string create_timestamp() const;
};
}
}
}

#endif /* SRC_MONITORS_TEMPERATURESMONITOR_H_ */
