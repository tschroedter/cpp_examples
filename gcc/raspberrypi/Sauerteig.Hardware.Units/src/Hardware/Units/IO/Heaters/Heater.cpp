/*
 * Heater.cpp
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#include <string>
#include "Heater.h"
#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/IO/Heaters/ISSRHeater.h"

#define DEFAULT_SSR_OUTPUT_PIN ((ssroutputpin) 2)

using namespace Hardware::Units::IO::Heaters;

Heater::Heater(ILogger_SPtr logger, ISSRHeater_SPtr heater)
        : m_logger(logger),
          m_heater(heater) {
    if (m_logger == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create Heater because 'm_logger' is null!",
                                                           "m_logger");
    }

    if (m_heater == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create Heater because 'm_heater' is null!",
                                                           "m_heater");
    }

    m_logger->set_prefix("Heater");
    m_heater->initialize(DEFAULT_SSR_OUTPUT_PIN);
}

void Heater::on() {
    m_heater->on();

    m_logger->debug("Heater is ON!");
}

void Heater::off() {
    m_heater->off();

    m_logger->debug("Heater is OFF!");
}

bool Heater::is_on() const {
    return m_heater->is_on();
}
