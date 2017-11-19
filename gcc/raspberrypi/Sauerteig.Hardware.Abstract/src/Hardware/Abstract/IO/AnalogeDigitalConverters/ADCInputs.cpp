/*
 * ADCTemperatures.cpp
 *
 *  Created on: 4 Nov. 2017
 *      Author: tom
 */

#include <mutex>
#include "Common/CommonTypes.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"

#include "ADCInputs.h"

#include "../../Interfaces/IO/AnalogeDigitalConverters/IADCInputs.h"

#define DEFAULT_NUMBER_OF_CHANNELS ((adcchannel)2)
#define DEFAULT_PIN_CS    ((wiringpipin) 0)
#define DEFAULT_PIN_DIO   ((wiringpipin) 1)
#define DEFAULT_PIN_CLK   ((wiringpipin) 2)

using namespace Hardware::Abstract::IO::AnalogeDigitalConverters;

ADCInputs::ADCInputs(IThreadSafeADC0832_SPtr adc0832)
        : m_adc0832(adc0832) {
    if (m_adc0832 == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create ADCTemperatures because 'm_adc0832' is null!",
                "m_adc0832");
    }

    m_adc0832->initialize(DEFAULT_NUMBER_OF_CHANNELS,
    DEFAULT_PIN_CS,
                          DEFAULT_PIN_DIO,
                          DEFAULT_PIN_CLK);
}

void ADCInputs::read_value_for_channel(adcchannel channel) {
    m_adc0832->read_value_for_channel(channel);
}

bool ADCInputs::is_value_valid_for_channel(adcchannel channel) const {
    bool is_valid = m_adc0832->is_value_valid_for_channel(channel);

    return is_valid;
}

uchar ADCInputs::get_value_for_channel(adcchannel channel) const {
    return (m_adc0832->get_value_for_channel(channel));
}

adcchannel ADCInputs::get_number_of_channels() const {
    return (m_adc0832->get_number_of_channels());
}
