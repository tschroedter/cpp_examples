/*
 * HeaterMonitor.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MONITORS_UNITS_HEATERMONITOR_H_
#define SRC_MONITORS_UNITS_HEATERMONITOR_H_

#include <thread>
#include <string>
#include <chrono>
#include <ctime>
#include <iostream>
#include "Common/Interfaces/IThreadInformationProvider.h"
#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/Monitors/Units/IHeaterMonitor.h"
#include "../../Interfaces/Monitors/Units/IHeaterOffMessageHandler.h"
#include "../../Interfaces/Monitors/Units/IHeaterOnMessageHandler.h"

#define HEATER_MONITOR_SLEEP_TIME_IN_SECONDS 30

using namespace std;
using namespace Sauerteig::Interfaces::Monitors::Units;

namespace Sauerteig {
namespace Monitors {
namespace Units {

class HeaterMonitor : public IHeaterMonitor {   // todo create one thread for heater, cooler, status
 public:
    HeaterMonitor(ILogger_SPtr logger, IThreadInformationProvider_SPtr provider, IHeaterOnMessageHandler_SPtr on_handler, IHeaterOffMessageHandler_SPtr off_handler);
    virtual ~HeaterMonitor() = default;

    void operator()() override {
        string pid = m_provider->get_thread_process_id_as_string();
        m_logger->info("SettingsMonitor PID: " + pid);

        while (1) {
            this_thread::sleep_for(chrono::seconds(HEATER_MONITOR_SLEEP_TIME_IN_SECONDS));

            update();

            m_logger->info(to_string());
        }
    }

    string to_string() const override;

 private:
    ILogger_SPtr m_logger = nullptr;
    IThreadInformationProvider_SPtr m_provider = nullptr;
    IHeaterOnMessageHandler_SPtr m_on_handler = nullptr;
    IHeaterOffMessageHandler_SPtr m_off_handler = nullptr;

    void update();
    bool m_is_heater_on = false;
};

}
}
}

#endif /* SRC_MONITORS_UNITS_HEATERMONITOR_H_ */
