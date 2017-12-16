/*
 * HeatingUnit.cpp
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#include <string>
#include "HeatingUnit.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/IO/Heaters/IHeater.h"
#include "../../Interfaces/IO/Heaters/IHeaterLED.h"

using namespace Hardware::Units::IO::Heaters;

HeatingUnit::HeatingUnit(ILogger_SPtr logger, IHeater_SPtr heater, IHeaterLED_SPtr led)
        : m_logger(logger),
          m_heater(heater),
          m_led(led) {
    if (m_logger == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create HeatingUnit because 'm_logger' is null!",
                                                           "m_logger");
    }

    if (m_heater == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create HeatingUnit because 'm_heater' is null!",
                                                           "m_heater");
    }

    if (m_led == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create HeatingUnit because 'm_led' is null!",
                                                           "m_led");
    }

    m_logger->set_prefix("HeatingUnit");
}

void HeatingUnit::on() {
    m_heater->on();
    m_led->on();

    m_logger->debug("Unit is ON!");
}

void HeatingUnit::off() {
    m_heater->off();
    m_led->off();

    m_logger->debug("Unit is OFF!");
}

bool HeatingUnit::is_on() const {
    return m_heater->is_on();
}

