/*
 * ThreadSafeADC0832.cpp
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#include <mutex>
#include "ThreadSafeADC0832.h"
#include "../../../Interfaces/IO/AnalogeDigitalConverters/IADC0832.h"
#include "../../../Exceptions/ArgumentInvalidExceptions.h"

ThreadSafeADC0832::ThreadSafeADC0832(IADC0832_SPtr adc0832)
        : m_adc0832(adc0832) {
    if (m_adc0832 == nullptr) {
        throw ArgumentInvalidException(
                "Can't create ThreadSafeADC0832 because 'm_adc0832' is null!",
                "m_adc0832");
    }
}

void ThreadSafeADC0832::read_value_for_channel(uint channel) {
    m_mutex.lock();

    m_adc0832->read_value_for_channel(channel);

    m_mutex.unlock();
}

bool ThreadSafeADC0832::is_value_valid_for_channel(uint channel) const {
    bool is_valid = m_adc0832->is_value_valid_for_channel(channel);

    return is_valid;
}

uchar ThreadSafeADC0832::get_value_for_channel(uint channel) const {
    return (m_adc0832->get_value_for_channel(channel));
}

uint ThreadSafeADC0832::get_number_of_channels() const {
    return (m_adc0832->get_number_of_channels());
}

uint ThreadSafeADC0832::get_pin_cs() const {
    return (m_adc0832->get_pin_cs());
}

uint ThreadSafeADC0832::get_pin_dio() const {
    return (m_adc0832->get_pin_dio());
}

uint ThreadSafeADC0832::get_pin_clk() const {
    return (m_adc0832->get_pin_clk());
}

void ThreadSafeADC0832::initialize(uint number_of_channels, uint pin_cs,
                                   uint pin_dio, uint pin_clk) {
    m_mutex.lock();

    m_adc0832->initialize(number_of_channels, pin_cs, pin_dio, pin_clk);

    m_mutex.unlock();
}

void ThreadSafeADC0832::set_adc0832(IADC0832_SPtr adc0832) {
    m_mutex.lock();

    m_adc0832 = adc0832;

    if (m_adc0832 == nullptr) {
        throw ArgumentInvalidException(
                "Can't create ThreadSafeADC0832 because 'adc0832' is null!",
                "adc0832");
    }

    m_mutex.unlock();
}
