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

using namespace Sauerteig::Monitors::Temperatures;

std::string TemperatureSensorToStringConverter::convert(ITemperatureSensorWithStatistics_SPtr sensor) const {
    celsius value = sensor->get_average_value();

    std::ostringstream oss_value;
    oss_value.precision(4);
    oss_value << value;

    std::string text_value { oss_value.str() };

    auto index_of_dot = text_value.find(".");

    if (index_of_dot == std::string::npos) {    // handle value = 12???
        text_value += ".00";
    }
    else
    {
        std::string text_after_dot = text_value.substr(index_of_dot+1);

        if (text_after_dot.length() == 1) { // handle value 12.3?
            text_value += "0";
        }
    }

    text_value += " C";

    double percent = sensor->get_average_percent_valid();

    std::ostringstream oss_percent;
    oss_percent.precision(4);
    oss_percent << percent;

    std::string text_percent { oss_percent.str() };

    if (text_percent.find(".") == std::string::npos) {
        text_percent += ".00";
    }

    text_percent += "% Valid";

    std::string result = text_value + " (" + text_percent + ")";

    return result;
}
