/*
 * HeaterMonitor.cpp
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#include <thread>
#include <string>
#include <chrono>
#include <ctime>
#include <iostream>
#include "HeaterMonitor.h"
#include "Common/Interfaces/IThreadInformationProvider.h"
#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/Monitors/Units/IHeaterMonitor.h"

using namespace std;
using namespace Common::Exceptions;
using namespace Sauerteig::Interfaces::Monitors::Units;

namespace Sauerteig {
namespace Monitors {
namespace Units {

HeaterMonitor::HeaterMonitor(ILogger_SPtr logger, IThreadInformationProvider_SPtr provider, IHeaterOnMessageHandler_SPtr on_handler, IHeaterOffMessageHandler_SPtr off_handler)
        : m_logger(logger),
          m_provider(provider),
          m_on_handler(on_handler),
          m_off_handler(off_handler){
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create HeaterMonitor because 'logger' is null!", "logger");
    }

    if (m_provider == nullptr) {
        throw ArgumentInvalidException("Can't create HeaterMonitor because 'provider' is null!", "provider");
    }

    if (m_on_handler == nullptr) {
        throw ArgumentInvalidException("Can't create HeaterMonitor because 'on_handler' is null!", "on_handler");
    }

    if (m_off_handler == nullptr) {
        throw ArgumentInvalidException("Can't create HeaterMonitor because 'off_handler' is null!", "off_handler");
    }

    m_logger->set_prefix("HeaterMonitor");
}

void HeaterMonitor::update()
{
    auto on = m_on_handler->get_last_message_id();
    auto off = m_off_handler->get_last_message_id();

    m_is_heater_on = (on > off);
}

string HeaterMonitor::to_string() const {
    string status = m_is_heater_on ? "On" : "Off";

    return "Heater is " + status;
}

}
}
}
