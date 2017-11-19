/*
 * Tmp36Logic.cpp
 *
 *  Created on: 14 Nov. 2017
 *      Author: tom
 */

#include "Tmp36Logic.h"

using namespace Hardware::IO::Sensors;

celsius Tmp36Logic::raw_to_celsius(uint raw_value) {
    // The voltage out is 0V at -50°C and 1.75V at 125°C. You can easily calculate
    // the temperature from the voltage in millivolts: Temp °C = 100*(reading in V) - 50
    double vr = 3.3 * raw_value / 255.0;
    double as_celsius = (100.0 * vr) - 50.0;

    return as_celsius;
}
