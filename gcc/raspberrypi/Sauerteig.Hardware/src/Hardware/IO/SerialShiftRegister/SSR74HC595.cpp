/*
 * SSR74HC595.cpp
 *
 *  Created on: 7 Nov. 2017
 *      Author: tom
 */

#include "SSR74HC595.h"
#include "wiringPi.h"
#include "sr595.h"
#include "Common/CommonTypes.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/ILogger.h"

#define PIN_BASE          ((uint)100)
#define NUMBER_OF_PINS    ((uint)10)
#define DEFAULT_PIN_DS    ((wiringpipin)26)
#define DEFAULT_PIN_ST_CP ((wiringpipin)28)
#define DEFAULT_PIN_SH_CP ((wiringpipin)29)

using namespace Hardware::IO::SerialShiftRegisters;

SSR74HC595::SSR74HC595(ILogger_SPtr logger)
        : m_logger(logger),
          m_pin_ds(DEFAULT_PIN_DS),
          m_pin_st_cp(DEFAULT_PIN_ST_CP),
          m_pin_sh_cp(DEFAULT_PIN_SH_CP),
          m_value(0) {
    if (m_logger == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create SSR74HC595 because 'm_logger' is null!",
                                                           "m_logger");
    }

    m_logger->set_prefix("SSR74HC595");
}

wiringpipin SSR74HC595::get_pin_ds() const {
    return (m_pin_ds);
}

wiringpipin SSR74HC595::get_pin_st_cp() const {
    return (m_pin_sh_cp);
}

wiringpipin SSR74HC595::get_pin_sh_cp() const {
    return (m_pin_sh_cp);
}

void SSR74HC595::initialize(wiringpipin pin_ds, wiringpipin pin_sh_cp, wiringpipin pin_st_cp) {
    m_pin_ds = pin_ds;
    m_pin_sh_cp = pin_sh_cp;
    m_pin_st_cp = pin_st_cp;

    sr595Setup(PIN_BASE, NUMBER_OF_PINS, m_pin_ds, m_pin_sh_cp, m_pin_st_cp);

    set_value(0);
}

void SSR74HC595::write_value() {
    m_logger->debug("Writing value: " + std::to_string(m_value));

    for (int bit = 0; bit < 8; bit++) {
        digitalWrite(100 + bit, m_value & (1 << bit));
        delay(1);
    }
}

void SSR74HC595::set_value(int value) {
    // TODO timeout
    m_value = value;

    write_value();
}

int SSR74HC595::get_value() const {
    m_logger->debug("Getting value: " + std::to_string(m_value));

    return m_value;
}
