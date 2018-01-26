/*
 * TemperatureOutside.cpp
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#include "TemperatureOutside.h"
#include "Common/CommonTypes.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/IADCTmp36.h"

#define CHANNEL_1 ((adcchannel) 1)

using namespace Common::Exceptions;
using namespace Hardware::Units::IO::Sensors;

TemperatureOutside::TemperatureOutside(IADCTmp36_SPtr tmp36)
        : m_tmp36(tmp36) {
    if (m_tmp36 == nullptr) {
        throw ArgumentInvalidException("Can't create TemperatureOutside because 'm_tmp36' is null!",
                                                           "m_tmp36");
    }

    m_tmp36->initialize(CHANNEL_1);
}

bool TemperatureOutside::is_value_valid() const {
    return (m_tmp36->is_value_valid());
}

celsius TemperatureOutside::get_value() const {
    return (m_tmp36->get_value());
}

void TemperatureOutside::refresh() {
    m_tmp36->refresh();
}

