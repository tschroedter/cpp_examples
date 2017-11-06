/*
 * TemperatureOutside.cpp
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#define CHANNEL_1 ((uint) 1)

#include "TemperatureOutside.h"
#include "../../Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/IO/Sensors/ITmp36.h"

TemperatureOutside::TemperatureOutside(ITmp36_SPtr tmp36)
        : m_tmp36(tmp36) {
    if (m_tmp36 == nullptr) {
        throw ArgumentInvalidException(
                "Can't create TemperatureOutside because 'm_tmp36' is null!",
                "m_tmp36");
    }

    m_tmp36->initialize(CHANNEL_1);
}

void TemperatureOutside::initialize(uint channel) {
    return (m_tmp36->initialize(channel));
}

bool TemperatureOutside::is_value_valid() const {
    return (m_tmp36->is_value_valid());
}

uint TemperatureOutside::get_value() const {
    return (m_tmp36->get_value());
}

uint TemperatureOutside::get_value_raw() const {
    return (m_tmp36->get_value_raw());
}

void TemperatureOutside::refresh() {
    m_tmp36->refresh();
}

