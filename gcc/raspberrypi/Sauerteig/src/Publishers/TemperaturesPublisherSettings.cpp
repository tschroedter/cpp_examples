/*
 * TemperaturesSettings.cpp
 *
 *  Created on: 2 Feb. 2018
 *      Author: tom
 */

#include "TemperaturesPublisherSettings.h"

#include <mutex>
#include "Common/CommonTypes.h"

namespace Sauerteig {
namespace Publishers {

celsius TemperaturesPublisherSettings::get_inside_average_value_correction() {
    m_mutex.lock();

    celsius value = m_inside_average_value_correction;

    m_mutex.unlock();

    return value;
}

void TemperaturesPublisherSettings::set_inside_average_value_correction(celsius value){
    m_mutex.lock();

    m_inside_average_value_correction = value;

    m_mutex.unlock();
}

celsius TemperaturesPublisherSettings::get_outside_average_value_correction() {
    m_mutex.lock();

    celsius value = m_outside_average_value_correction;

    m_mutex.unlock();

    return value;
}

void TemperaturesPublisherSettings::set_outside_average_value_correction(celsius value) {
    m_mutex.lock();

    m_outside_average_value_correction = value;

    m_mutex.unlock();

}

}
}

