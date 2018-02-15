/*
 * UnitsMonitor.cpp
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#include "UnitsMonitor.h"

#include <thread>
#include <string>
#include <chrono>
#include <ctime>
#include <iostream>
#include "Common/Interfaces/IThreadInformationProvider.h"
#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/Monitors/Units/IUnitsMonitor.h"
#include "../../Interfaces/Monitors/Units/ICoolerOffMessageHandler.h"
#include "../../Interfaces/Monitors/Units/ICoolerOnMessageHandler.h"

using namespace std;
using namespace Common::Exceptions;
using namespace Sauerteig::Interfaces::Monitors::Units;

namespace Sauerteig {
namespace Monitors {
namespace Units {

UnitsMonitor::UnitsMonitor(ILogger_SPtr logger,
                           IThreadInformationProvider_SPtr provider,
                           IHeaterOnMessageHandler_SPtr heater_on_handler,
                           IHeaterOffMessageHandler_SPtr heater_off_handler,
                           ICoolerOnMessageHandler_SPtr cooler_on_handler,
                           ICoolerOffMessageHandler_SPtr cooler_off_handler)
        : m_logger(logger),
          m_provider(provider),
          m_heater_on_handler(heater_on_handler),
          m_heater_off_handler(heater_off_handler),
          m_cooler_on_handler(cooler_on_handler),
          m_cooler_off_handler(cooler_off_handler) {
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create UnitsMonitor because 'logger' is null!", "logger");
    }

    if (m_provider == nullptr) {
        throw ArgumentInvalidException("Can't create UnitsMonitor because 'provider' is null!", "provider");
    }

    if (m_heater_on_handler == nullptr) {
        throw ArgumentInvalidException("Can't create UnitsMonitor because 'heater_on_handler' is null!", "heater_on_handler");
    }

    if (m_heater_off_handler == nullptr) {
        throw ArgumentInvalidException("Can't create UnitsMonitor because 'heater_off_handler' is null!", "heater_off_handler");
    }

    if (m_cooler_on_handler == nullptr) {
        throw ArgumentInvalidException("Can't create UnitsMonitor because 'cooler_on_handler' is null!", "cooler_on_handler");
    }

    if (m_cooler_off_handler == nullptr) {
        throw ArgumentInvalidException("Can't create UnitsMonitor because 'cooler_off_handler' is null!", "cooler_off_handler");
    }

    m_logger->set_prefix("UnitsMonitor");
}

void UnitsMonitor::update()
{
    auto heater_on = m_heater_on_handler->get_last_message_id();
    auto heater_off = m_heater_off_handler->get_last_message_id();

    m_is_heater_on = (heater_on > heater_off);

    auto cooler_on = m_cooler_on_handler->get_last_message_id();
    auto cooler_off = m_cooler_off_handler->get_last_message_id();

    m_is_cooler_on = (cooler_on > cooler_off);
}

string UnitsMonitor::to_string() const {
    string heater_status = m_is_heater_on ? "On" : "Off";
    string cooler_status = m_is_cooler_on ? "On" : "Off";

    return "Heater is " + heater_status + " Cooler is " + cooler_status;
}

}
}
}
