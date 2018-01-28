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
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensorWithStatistics.h"

using namespace std;
using namespace Sauerteig::Monitors::Temperatures;

string TemperatureSensorToStringConverter::format_number(celsius value) const {
    ostringstream oss_value;
    oss_value.precision(4);
    oss_value << value;
    string text_value { oss_value.str() };

    // handle digits after dot
    auto index_of_dot = text_value.find(".");
    if (index_of_dot == string::npos) {
        // handle value = 12???
        text_value += ".00";
    } else {
        string text_after_dot = text_value.substr(index_of_dot + 1);
        if (text_after_dot.length() == 1) {
            // handle value 12.3?
            text_value += "0";
        }
    }

    // handle digits before dot
    index_of_dot = text_value.find(".");
    auto text_before_dot = text_value.substr(0, index_of_dot);
    auto digits_before_dot = text_before_dot.length();

    string spaces;

    for (size_t i = 3; i > digits_before_dot; i--) {
        spaces += " ";
    }

    text_value = spaces + text_value;

    return text_value;
}

string TemperatureSensorToStringConverter::convert(celsius value, double percent) const {

    string text_value = format_number(value);

    text_value += " C";

    ostringstream oss_percent;
    oss_percent.precision(4);
    oss_percent << percent;

    string text_percent = format_number(percent);

    text_percent += "% Valid";

    string result = text_value + " (" + text_percent + ")";

    return result;
}

string TemperatureSensorToStringConverter::convert(ITemperatureSensorWithStatistics_SPtr sensor) const {
    celsius value = sensor->get_average_value();
    double percent = sensor->get_average_percent_valid();

    string result = convert(value, percent);

    return result;
}
