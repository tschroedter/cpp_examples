/*
 * Heater.cpp
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#include <string>
#include "Cooler.h"
#include "Common/AOP/AOP.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/IO/Coolers/ISSRCooler.h"

#define DEFAULT_SSR_OUTPUT_PIN ((ssroutputpin) 0)

using namespace Common::Exceptions;
using namespace Hardware::Units::IO::Coolers;

Cooler::Cooler(ILogger_SPtr logger, ISSRCooler_SPtr cooler)
        : m_logger(logger),
          m_cooler(cooler) {
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create Cooler because 'm_logger' is null!",
                                                           "m_logger");
    }

    if (m_cooler == nullptr) {
        throw ArgumentInvalidException("Can't create Cooler because 'm_cooler' is null!",
                                                           "m_cooler");
    }

    m_logger->set_prefix("Cooler");
    m_cooler->initialize(DEFAULT_SSR_OUTPUT_PIN);
}

void Cooler::on() {
    m_cooler->on();

    m_logger->debug("Cooler is ON!");
}

void Cooler::off() {
    m_cooler->off();

    m_logger->debug("Cooler is OFF!");
}

bool Cooler::is_on() const {
    return m_cooler->is_on();
}
