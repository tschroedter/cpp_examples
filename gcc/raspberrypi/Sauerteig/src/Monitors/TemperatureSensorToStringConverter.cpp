/*
 * TemperatureSensorToString.cpp
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#include <string>
#include <sstream>
#include <iostream>
#include <math.h>
#include "TemperatureSensorToStringConverter.h"
#include "Common/CommonTypes.h"

using namespace Sauerteig::Monitors;

std::string TemperatureSensorToStringConverter::convert(
        ITemperatureSensor_SPtr sensor) const {
    sensor->refresh();
    celsius value = sensor->get_value();
    bool is_valid = sensor->is_value_valid();

    std::string valid = is_valid ? "VALID" : "INVALID";

    std::ostringstream oss;
    oss.precision(4);
    oss << value;

    std::string text { oss.str() };

    if (text.find(".") == std::string::npos) {
        text += ".00";
    }

    text += " C " + valid;

    return text;
}
