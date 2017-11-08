/*
 * TemperatureInside.cpp
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */
#define CHANNEL_0 ((uint) 0)

#include "TemperatureInside.h"
#include "./Common/Exceptions/ArgumentInvalidExceptions.h"
#include "./Hardware/Interfaces/IO/Sensors/ITmp36.h"

TemperatureInside::TemperatureInside(ITmp36_SPtr tmp36)
        : m_tmp36(tmp36) {
    if (m_tmp36 == nullptr) {
        throw ArgumentInvalidException(
                "Can't create TemperatureInside because 'm_tmp36' is null!",
                "m_tmp36");
    }

    m_tmp36->initialize(CHANNEL_0);
}

void TemperatureInside::initialize(uint channel) {
    return (m_tmp36->initialize(channel));
}

bool TemperatureInside::is_value_valid() const {
    return (m_tmp36->is_value_valid());
}

uint TemperatureInside::get_value() const {
    return (m_tmp36->get_value());
}

uint TemperatureInside::get_value_raw() const {
    return (m_tmp36->get_value_raw());
}

void TemperatureInside::refresh() {
    m_tmp36->refresh();
}

