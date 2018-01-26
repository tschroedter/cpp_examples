/*
 * HeatingUnit.cpp
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#include "CoolingUnit.h"

#include <string>
#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/IO/Heaters/IHeater.h"
#include "../../Interfaces/IO/Heaters/IHeaterLED.h"

using namespace Common::Exceptions;
using namespace Hardware::Units::IO::Coolers;

CoolingUnit::CoolingUnit(ILogger_SPtr logger, ICooler_SPtr cooler, ICoolerLED_SPtr led)
        : m_logger(logger),
          m_cooler(cooler),
          m_led(led) {
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create CoolingUnit because 'm_logger' is null!",
                                                           "m_logger");
    }

    if (m_cooler == nullptr) {
        throw ArgumentInvalidException("Can't create CoolingUnit because 'm_cooler' is null!",
                                                           "m_cooler");
    }

    if (m_led == nullptr) {
        throw ArgumentInvalidException("Can't create CoolingUnit because 'm_led' is null!",
                                                           "m_led");
    }

    m_logger->set_prefix("CoolingUnit");
}

void CoolingUnit::on() {
    m_cooler->on();
    m_led->on();

    m_logger->debug("Unit is ON!");
}

void CoolingUnit::off() {
    m_cooler->off();
    m_led->off();

    m_logger->debug("Unit is OFF!");
}

bool CoolingUnit::is_on() const {
    return m_cooler->is_on();
}

