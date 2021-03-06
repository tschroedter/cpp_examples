/*
 * ThreadSafeADC0832.cpp
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#include <mutex>
#include "ThreadSafeADC0832.h"
#include "Hardware/Interfaces/IO/AnalogeDigitalConverters/IADC0832.h"
#include "./Common/Exceptions/ArgumentInvalidExceptions.h"

using namespace Hardware::Abstract::IO::AnalogeDigitalConverters::ThreadSafe;

ThreadSafeADC0832::ThreadSafeADC0832(IADC0832_SPtr adc0832)
        : m_adc0832(adc0832) {
    if (m_adc0832 == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create ThreadSafeADC0832 because 'm_adc0832' is null!", "m_adc0832");
    }
}

void ThreadSafeADC0832::read_value_for_channel(adcchannel channel) {
    m_mutex.lock();

    m_adc0832->read_value_for_channel(channel);

    m_mutex.unlock();
}

bool ThreadSafeADC0832::is_value_valid_for_channel(adcchannel channel) const {
    bool is_valid = m_adc0832->is_value_valid_for_channel(channel);

    return is_valid;
}

uchar ThreadSafeADC0832::get_value_for_channel(adcchannel channel) const {
    return (m_adc0832->get_value_for_channel(channel));
}

adcchannel ThreadSafeADC0832::get_number_of_channels() const {
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

void ThreadSafeADC0832::initialize(adcchannel number_of_channels, wiringpipin pin_cs, wiringpipin pin_dio,
                                   wiringpipin pin_clk) {
    m_mutex.lock();

    m_adc0832->initialize(number_of_channels, pin_cs, pin_dio, pin_clk);

    m_mutex.unlock();
}

void ThreadSafeADC0832::set_adc0832(IADC0832_SPtr adc0832) {
    m_mutex.lock();

    m_adc0832 = adc0832;

    if (m_adc0832 == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException("Can't create ThreadSafeADC0832 because 'adc0832' is null!",
                                                           "adc0832");
    }

    m_mutex.unlock();
}
