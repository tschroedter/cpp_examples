/*
 * TemperatureInside.cpp
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#include "Common/CommonTypes.h"
#include "TemperatureInside.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/IO/Sensors/IADCTmp36.h"

#define CHANNEL_0 ((adcchannel) 0)

using namespace Hardware::Abstract::IO::Sensors;

TemperatureInside::TemperatureInside(IADCTmp36_SPtr tmp36)
        : m_tmp36(tmp36) {
    if (m_tmp36 == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create TemperatureInside because 'm_tmp36' is null!",
                "m_tmp36");
    }

    m_tmp36->initialize(CHANNEL_0);
}

bool TemperatureInside::is_value_valid() const {
    return (m_tmp36->is_value_valid());
}

celsius TemperatureInside::get_value() const {
    return (m_tmp36->get_value());
}

void TemperatureInside::refresh() {
    m_tmp36->refresh();
}

