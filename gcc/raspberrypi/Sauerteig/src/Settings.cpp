/*
 * TemperaturesSettings.cpp
 *
 *  Created on: 2 Feb. 2018
 *      Author: tom
 */

#include "Settings.h"

#include <mutex>
#include <string>
#include "Common/CommonTypes.h"

using namespace std;

namespace Sauerteig {

celsius Settings::get_inside_average_value_correction() {
    m_mutex.lock();

    celsius value = m_inside_average_value_correction;

    m_mutex.unlock();

    return value;
}

void Settings::set_inside_average_value_correction(celsius value){
    m_mutex.lock();

    m_inside_average_value_correction = value;

    m_mutex.unlock();
}

celsius Settings::get_outside_average_value_correction() {
    m_mutex.lock();

    celsius value = m_outside_average_value_correction;

    m_mutex.unlock();

    return value;
}

void Settings::set_outside_average_value_correction(celsius value) {
    m_mutex.lock();

    m_outside_average_value_correction = value;

    m_mutex.unlock();

}

string Settings::to_string() {  // Todo this should be another object

    m_mutex.lock();

    celsius inside = m_inside_average_value_correction;
    celsius outside = m_outside_average_value_correction;

    m_mutex.unlock();

    string text =
            "Inside Average Value Correction = " + std::to_string(inside) + "\n" +
            "Outside Average Value Correction = " + std::to_string(outside);

    return text;
}

}

