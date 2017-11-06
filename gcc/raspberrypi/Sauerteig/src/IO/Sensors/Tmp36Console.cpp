/*
 * Tmp36Console.cpp
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#include <iostream>
#include <thread>
#include "../../CommonTypes.h"
#include "Tmp36Console.h"
#include "../../Interfaces/IO/Sensors/ITmp36.h"

Tmp36Console::Tmp36Console(ITmp36_SPtr tmp36)
        : m_tmp36(tmp36) {
}

void Tmp36Console::initialize(uint channel, const std::string description) {
    m_tmp36->initialize(channel);
    m_description = description;
}

void Tmp36Console::print() const {

    m_tmp36->refresh();

    std::thread::id id = std::this_thread::get_id();

    uint value = m_tmp36->get_value();
    bool is_valid = m_tmp36->is_value_valid();

    std::string valid = is_valid ? "VALID" : "INVALID";

    std::cout << "[" << id << ", " << m_description << "] " << value << "C "
              << valid << "\n";

}

