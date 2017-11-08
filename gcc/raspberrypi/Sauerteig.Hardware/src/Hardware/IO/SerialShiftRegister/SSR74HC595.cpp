/*
 * SSR74HC595.cpp
 *
 *  Created on: 7 Nov. 2017
 *      Author: tom
 */

#include <iostream>
#include "SSR74HC595.h"
#include "wiringPi.h"
#include "sr595.h"
#include "Common/CommonTypes.h"

#define PIN_BASE          ((uint)100)
#define NUMBER_OF_PINS    ((uint)10)
#define DEFAULT_PIN_DS    ((uint)26)
#define DEFAULT_PIN_ST_CP ((uint)28)
#define DEFAULT_PIN_SH_CP ((uint)29)

SSR74HC595::SSR74HC595()
        : m_pin_ds(DEFAULT_PIN_DS),
          m_pin_st_cp(DEFAULT_PIN_ST_CP),
          m_pin_sh_cp(DEFAULT_PIN_SH_CP) {
}

uint SSR74HC595::get_pin_ds() const {
    return (m_pin_ds);
}

uint SSR74HC595::get_pin_st_cp() const {
    return (m_pin_sh_cp);
}

uint SSR74HC595::get_pin_sh_cp() const {
    return (m_pin_sh_cp);
}

void SSR74HC595::initialize(uint pin_ds, uint pin_st_cp, uint pin_sh_cp) {
    m_pin_ds = pin_ds;
    m_pin_st_cp = pin_st_cp;
    m_pin_sh_cp = pin_sh_cp;

    sr595Setup(PIN_BASE, NUMBER_OF_PINS, m_pin_ds, m_pin_st_cp, m_pin_sh_cp);
}

