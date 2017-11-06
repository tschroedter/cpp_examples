/*
 * TemperatureSensorToString.cpp
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#include "TemperatureSensorToStringConverter.h"

std::string TemperatureSensorToStringConverter::convert(
        ITemperatureSensor_SPtr sensor) const {
    sensor->refresh();
    uint value = sensor->get_value();
    bool is_valid = sensor->is_value_valid();

    std::string valid = is_valid ? "VALID" : "INVALID";

    std::string text = std::to_string(value) + " C " + valid;

    return text;
}
