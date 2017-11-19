/*
 * ADC0832.cpp
 *
 *  Created on: 31 Oct. 2017
 *      Author: tom
 */

#include <wiringPi.h>
#include <stdio.h>
#include <vector>
#include "ADC0832.h"

#include <Common/Exceptions/ADCChannelInvalidException.h>

#include "../../Interfaces/IO/AnalogeDigitalConverters/IADC0832.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"

using namespace Hardware::IO::AnalogeDigitalConverters;

void ADC0832::initialize(adcchannel number_of_channels, wiringpipin pin_cs,
                         wiringpipin pin_dio, wiringpipin pin_clk) {
    m_number_of_channels = number_of_channels;
    m_pin_cs = pin_cs;
    m_pin_dio = pin_dio;
    m_pin_clk = pin_clk;

    pinMode(m_pin_cs, OUTPUT);
    pinMode(m_pin_clk, OUTPUT);

    initialize_with_default_values();
}

void ADC0832::initialize_with_default_values() {
    for (uint i = 0; i <= m_number_of_channels; i++) {
        m_data.push_back(0);
        m_is_data_valid.push_back(false);
    }
}

ADC0832::ADC0832() {
}

ADC0832::ADC0832(adcchannel number_of_channels, wiringpipin pin_cs,
                 wiringpipin pin_dio, wiringpipin pin_clk)
        : m_number_of_channels(number_of_channels),
          m_pin_cs(pin_cs),
          m_pin_dio(pin_dio),
          m_pin_clk(pin_clk) {
}

ADC0832::~ADC0832() {
    m_data.clear();
    m_is_data_valid.clear();
}

void ADC0832::validate_channel(adcchannel channel) const {
    if (channel >= m_number_of_channels || channel < 0) {
        throw Common::Exceptions::ADCChannelInvalidException(
                "Invalid channel '" + std::to_string(channel)
                        + "'! Channel must 0 <= channel < "
                        + std::to_string(m_number_of_channels) + "!");
    }
}

bool ADC0832::is_value_valid_for_channel(adcchannel channel) const {
    validate_channel(channel);

    return (m_is_data_valid[channel]);
}

uint ADC0832::get_pin_cs() const {
    return (m_pin_cs);
}

uint ADC0832::get_pin_dio() const {
    return (m_pin_dio);
}
uint ADC0832::get_pin_clk() const {
    return (m_pin_clk);
}

uchar ADC0832::read_value_for_channel_1() {
    uchar dat1 = 0;

    for (size_t i = 0; i < 8; i++) {
        digitalWrite(m_pin_clk, 1);
        delayMicroseconds(2);
        digitalWrite(m_pin_clk, 0);
        delayMicroseconds(2);
        pinMode(m_pin_dio, INPUT);
        dat1 = dat1 << 1 | digitalRead(m_pin_dio);
    }
    return (dat1);
}

uchar ADC0832::read_value_for_channel_2() {
    uchar dat2 = 0;

    for (size_t i = 0; i < 8; i++) {
        dat2 = dat2 | ((uchar) ((digitalRead(m_pin_dio))) << i);
        digitalWrite(m_pin_clk, 1);
        delayMicroseconds(2);
        digitalWrite(m_pin_clk, 0);
        delayMicroseconds(2);
    }
    return dat2;
}

void ADC0832::before_for_read_value(adcchannel channel) {
    digitalWrite(m_pin_cs, 0);
    digitalWrite(m_pin_clk, 0);
    digitalWrite(m_pin_dio, 1);
    delayMicroseconds(2);
    digitalWrite(m_pin_clk, 1);
    delayMicroseconds(2);
    digitalWrite(m_pin_clk, 0);
    digitalWrite(m_pin_dio, 1);
    delayMicroseconds(2);
    digitalWrite(m_pin_clk, 1);
    delayMicroseconds(2);
    digitalWrite(m_pin_clk, 0);
    digitalWrite(m_pin_dio, channel);
    delayMicroseconds(2);
    digitalWrite(m_pin_clk, 1);
    digitalWrite(m_pin_dio, 0);
    delayMicroseconds(2);
    digitalWrite(m_pin_clk, 0);
    digitalWrite(m_pin_dio, 1);
    delayMicroseconds(2);

    pinMode(m_pin_dio, OUTPUT);
}

void ADC0832::after_read_value() {
    digitalWrite(m_pin_cs, 1);
    pinMode(m_pin_dio, OUTPUT);
}

void ADC0832::read_value_for_channel(adcchannel channel) {
    // TODO add timeout
    validate_channel(channel);

    before_for_read_value(channel);

    uchar data_1 = read_value_for_channel_1();
    uchar data_2 = read_value_for_channel_2();

    m_data[channel] = data_1;

    m_is_data_valid[channel] = data_1 == data_2;

    after_read_value();
}

adcchannel ADC0832::get_number_of_channels() const {
    return (m_number_of_channels);
}

uchar ADC0832::get_value_for_channel(adcchannel channel) const {
    validate_channel(channel);

    return (m_data[channel]);
}
