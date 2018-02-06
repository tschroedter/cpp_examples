/*
 * SettingsMonitor.h
 *
 *  Created on: 6 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MONITORS_SETTINGS_SETTINGSMONITOR_H_
#define SRC_MONITORS_SETTINGS_SETTINGSMONITOR_H_

#include <thread>
#include <string>
#include "Common/Interfaces/IThreadInformationProvider.h"
#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/Monitors/Settings/ISettingsMonitor.h"
#include "../../Interfaces/ISettings.h"

#define SETTINGS_MONITOR_SLEEP_TIME_IN_SECONDS 60

using namespace Sauerteig::Interfaces::Monitors::Settings;

namespace Sauerteig {
namespace Monitors {
namespace Settings {

class SettingsMonitor : public ISettingsMonitor {
 public:
    SettingsMonitor(ILogger_SPtr logger, IThreadInformationProvider_SPtr provider, ISettings_SPtr settings);
    virtual ~SettingsMonitor() = default;

    void operator()() override {
        string pid = m_provider->get_thread_process_id_as_string();
        m_logger->info("SettingsMonitor PID: " + pid);

        while (1) {
            this_thread::sleep_for(chrono::seconds(SETTINGS_MONITOR_SLEEP_TIME_IN_SECONDS));

            m_logger->info(to_string());
        }
    }

    string to_string() const override;

 private:
    ILogger_SPtr m_logger = nullptr;
    IThreadInformationProvider_SPtr m_provider = nullptr;
    ISettings_SPtr m_settings = nullptr;
};

}
}
}

#endif /* SRC_MONITORS_SETTINGS_SETTINGSMONITOR_H_ */
