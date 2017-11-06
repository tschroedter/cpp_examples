/*
 * ADCTemperatures.cpp
 *
 *  Created on: 4 Nov. 2017
 *      Author: tom
 */

#include <mutex>
#include "../../Exceptions/ArgumentInvalidExceptions.h"
#include "ADCTemperatures.h"
#include "../../Interfaces/IO/AnalogeDigitalConverters/IADCTemperatures.h"
#include "../../CommonTypes.h"

#define DEFAULT_NUMBER_OF_CHANNELS ((uint)2)
#define DEFAULT_ADC_PIN_CS    ((uint)0)
#define DEFAULT_ADC_PIN_DIO   ((uint)1)
#define DEFAULT_ADC_PIN_CLK   ((uint)2)

ADCTemperatures::ADCTemperatures(IThreadSafeADC0832_SPtr adc0832)
        : m_adc0832(adc0832) {
    if (m_adc0832 == nullptr) {
        throw ArgumentInvalidException(
                "Can't create ADCTemperatures because 'm_adc0832' is null!",
                "m_adc0832");
    }

    m_adc0832->initialize(DEFAULT_NUMBER_OF_CHANNELS,
    DEFAULT_ADC_PIN_CS,
                          DEFAULT_ADC_PIN_DIO,
                          DEFAULT_ADC_PIN_CLK);
}

void ADCTemperatures::read_value_for_channel(uint channel) {
    m_adc0832->read_value_for_channel(channel);
}

bool ADCTemperatures::is_value_valid_for_channel(uint channel) const {
    bool is_valid = m_adc0832->is_value_valid_for_channel(channel);

    return is_valid;
}

uchar ADCTemperatures::get_value_for_channel(uint channel) const {
    return (m_adc0832->get_value_for_channel(channel));
}

uint ADCTemperatures::get_number_of_channels() const {
    return (m_adc0832->get_number_of_channels());
}

void ADCTemperatures::initialize(uint number_of_channels, uint pin_cs,
                                 uint pin_dio, uint pin_clk) {
    m_adc0832->initialize(number_of_channels, pin_cs, pin_dio, pin_clk);
}
