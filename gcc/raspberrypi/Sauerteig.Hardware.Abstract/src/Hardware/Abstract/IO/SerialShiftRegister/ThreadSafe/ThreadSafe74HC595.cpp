/*
 * ThreadSafe74HC595.cpp
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#include <mutex>
#include "ThreadSafe74HC595.h"
#include "Common/CommonTypes.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Hardware/Interfaces/IO/SerialShiftRegister/I74HC595.h"

using namespace Hardware::Abstract::IO::SerialShiftRegister::ThreadSafe;

ThreadSafe74HC595::ThreadSafe74HC595(I74HC595_SPtr ssr)
        : m_ssr(ssr) {
    if (m_ssr == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create ThreadSafe74HC595 because 'm_ssr' is null!",
                                                           "m_ssr");
    }
}

wiringpipin ThreadSafe74HC595::get_pin_ds() const {
    return m_ssr->get_pin_ds();
}

wiringpipin ThreadSafe74HC595::get_pin_st_cp() const {
    return m_ssr->get_pin_st_cp();
}

wiringpipin ThreadSafe74HC595::get_pin_sh_cp() const {
    return m_ssr->get_pin_sh_cp();
}

void ThreadSafe74HC595::initialize(wiringpipin pin_ds, wiringpipin pin_sh_dp, wiringpipin pin_sh_cp) {
    m_mutex.lock();

    m_ssr->initialize(pin_ds, pin_sh_dp, pin_sh_cp);

    m_mutex.unlock();
}

void ThreadSafe74HC595::set_value(int value) {
    m_mutex.lock();

    m_ssr->set_value(value);

    m_mutex.unlock();
}

int ThreadSafe74HC595::get_value() {
    m_mutex.lock();

    int value = m_ssr->get_value();

    m_mutex.unlock();

    return value;
}
