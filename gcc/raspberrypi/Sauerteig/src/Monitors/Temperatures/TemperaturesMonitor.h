/*
 * TemperaturesMonitor.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_MONITORS_TEMPERATURESMONITOR_H_
#define SRC_MONITORS_TEMPERATURESMONITOR_H_

#include <Common/Interfaces/IThreadInformationProvider.h>
#include <thread>
#include <string.h>
#include <iostream>
#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/Monitors/Temperatures/ITemperaturesMonitor.h"
#include "../../Interfaces/Monitors/Temperatures/ITemperatureSensorToStringConverter.h"
#include "../../Interfaces/Monitors/Temperatures/ITemperaturesMessageHandler.h"

namespace Sauerteig {
namespace Monitors {
namespace Temperatures {
class TemperaturesMonitor : public Sauerteig::Interfaces::Monitors::Temperatures::ITemperaturesMonitor {
 public:
    TemperaturesMonitor(ILogger_SPtr logger,
                        IThreadInformationProvider_SPtr provider,
                        ITemperaturesMessageHandler_SPtr handler,
                        ITemperatureSensorToStringConverter_SPtr converter);
    virtual ~TemperaturesMonitor() = default;

    void operator()() override {
        std::string pid = m_provider->get_thread_process_id_as_string();
        m_logger->info("TemperaturesMonitor PID: " + pid);

        while (1) {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            m_logger->info(to_string());
        }
    }

    std::string to_string() const override;

 private:
    ILogger_SPtr m_logger = nullptr;
    IThreadInformationProvider_SPtr m_provider = nullptr;
    ITemperaturesMessageHandler_SPtr m_handler = nullptr;
    ITemperatureSensorToStringConverter_SPtr m_converter = nullptr;
};
}
}
}

#endif /* SRC_MONITORS_TEMPERATURESMONITOR_H_ */
