/*
 * SettingsMonitor.cpp
 *
 *  Created on: 6 Feb. 2018
 *      Author: tom
 */

#include <thread>
#include <string>
#include "SettingsMonitor.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/IThreadInformationProvider.h"
#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/ISettings.h"

using namespace std;
using namespace Common::Exceptions;

namespace Sauerteig {
namespace Monitors {
namespace Settings {

SettingsMonitor::SettingsMonitor(
        ILogger_SPtr logger,
        IThreadInformationProvider_SPtr provider,
        ISettings_SPtr settings)
    : m_logger(logger),
      m_provider(provider),
      m_settings(settings) {
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create SettingsMonitor because 'logger' is null!", "logger");
    }

    if (m_provider == nullptr) {
        throw ArgumentInvalidException("Can't create SettingsMonitor because 'provider' is null!", "provider");
    }

    if (m_settings == nullptr) {
        throw ArgumentInvalidException("Can't create SettingsMonitor because 'settings' is null!", "settings");
    }

    m_logger->set_prefix("SettingsMonitor");
}

string SettingsMonitor::to_string() const {
    string message = "Current settings:\n" + m_settings->to_string();

    return message;
}

}
}
}
