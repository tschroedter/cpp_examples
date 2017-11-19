/*
 * Logger.cpp
 *
 *  Created on: 18 Nov. 2017
 *      Author: tom
 */

#include "Logger.h"
#include <iostream>
#include <string>

using namespace Common;

void Logger::debug(std::string message) {
    std::cout << message << std::endl;
}

void Logger::error(std::string message) {
    std::cout << message << std::endl;
}

void Logger::info(std::string message) {
    std::cout << message << std::endl;
}
