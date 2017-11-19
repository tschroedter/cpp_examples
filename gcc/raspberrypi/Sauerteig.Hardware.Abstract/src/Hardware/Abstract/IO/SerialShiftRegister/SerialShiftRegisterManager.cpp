/*
 * SerialShiftRegisterManager.cpp
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#include <iostream>
#include <bitset>
#include "Common/CommonTypes.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "SerialShiftRegisterManager.h"
#include "../../Interfaces/IO/SerialShiftRegister/ThreadSafe/IThreadSafe74HC595.h"

using namespace Hardware::Abstract::IO::SerialShiftRegister;

SerialShiftRegisterManager::SerialShiftRegisterManager(
        IThreadSafe74HC595_SPtr ssr)
        : m_ssr(ssr) {
    if (m_ssr == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create SerialShiftRegisterManager because 'm_ssr' is null!",
                "m_ssr");
    }
}

void SerialShiftRegisterManager::initialize(wiringpipin pin_ds,
                                            wiringpipin pin_sh_dp,
                                            wiringpipin pin_sh_cp) {
    m_ssr->initialize(pin_ds, pin_sh_dp, pin_sh_cp);
}

void SerialShiftRegisterManager::high(ssroutputpin pin) {
    int value = m_ssr->get_value();
    value |= 1UL << pin;

    m_ssr->set_value(value);
}

void SerialShiftRegisterManager::low(ssroutputpin pin) {
    int value = m_ssr->get_value();
    value &= ~(1UL << pin);

    m_ssr->set_value(value);
}

bool SerialShiftRegisterManager::is_high(ssroutputpin pin) const {
    int value = m_ssr->get_value();

    return value & (1UL << pin);
}

