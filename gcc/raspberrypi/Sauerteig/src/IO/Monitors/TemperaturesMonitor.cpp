/*
 * TemperaturesMonitor.cpp
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include "TemperaturesMonitor.h"
#include "../../Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensor.h"
#include "../../Interfaces/IO/Sensors/ITemperatureInside.h"
#include "../../Interfaces/IO/Sensors/ITemperatureOutside.h"
#include "../../Interfaces/IO/Monitors/ITemperatureSensorToStringConverter.h"

TemperaturesMonitor::TemperaturesMonitor(
        ITemperatureInside_SPtr inside, ITemperatureOutside_SPtr outside,
        ITemperatureSensorToStringConverter_SPtr converter)
        : m_inside(inside),
          m_outside(outside),
          m_converter(converter) {
    if (m_inside == nullptr) {
        throw ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'm_inside' is null!",
                "m_inside");
    }

    if (m_outside == nullptr) {
        throw ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'm_outside' is null!",
                "m_outside");
    }

    if (m_converter == nullptr) {
        throw ArgumentInvalidException(
                "Can't create TemperaturesMonitor because 'm_converter' is null!",
                "m_converter");
    }
}

std::string TemperaturesMonitor::create_timestamp() const {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    std::string datetime { std::ctime(&now_time_t) };
    std::string datetime_without_return = datetime.substr(
            0, datetime.length() - 1);

    std::string text = "[" + datetime_without_return + "] ";

    return (text);
}

void TemperaturesMonitor::print() const {
    std::string timestamp = create_timestamp();

    std::string inside = m_converter->convert(m_inside);
    std::cout << timestamp << "Temperature Inside : " << inside << "\n";

    std::string outside = m_converter->convert(m_outside);
    std::cout << timestamp << "Temperature Outside: " << outside << "\n";
}

