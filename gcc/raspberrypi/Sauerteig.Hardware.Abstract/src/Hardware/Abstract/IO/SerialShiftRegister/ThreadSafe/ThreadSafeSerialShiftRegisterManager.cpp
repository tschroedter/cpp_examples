/*
 * ThreadSafeSerialShiftRegisterManager.cpp
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#include <mutex>
#include "ThreadSafeSerialShiftRegisterManager.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../../Interfaces/IO/SerialShiftRegister/ISerialShiftRegisterManager.h"

using namespace Hardware::Abstract::IO::SerialShiftRegister::ThreadSafe;

ThreadSafeSerialShiftRegisterManager::ThreadSafeSerialShiftRegisterManager(
        ISerialShiftRegisterManager_SPtr manager)
        : m_manager(manager) {
    if (m_manager == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create ThreadSafeSerialShiftRegisterManager because 'm_manager' is null!",
                "m_manager");
    }
}

void ThreadSafeSerialShiftRegisterManager::initialize(wiringpipin pin_ds,
                                                      wiringpipin pin_sh_dp,
                                                      wiringpipin pin_sh_cp) {
    m_mutex.lock();

    m_manager->initialize(pin_ds, pin_sh_dp, pin_sh_cp);

    m_mutex.unlock();
}

void ThreadSafeSerialShiftRegisterManager::high(ssroutputpin pin) {
    m_mutex.lock();

    m_manager->high(pin);

    m_mutex.unlock();
}

void ThreadSafeSerialShiftRegisterManager::low(ssroutputpin pin) {
    m_mutex.lock();

    m_manager->low(pin);

    m_mutex.unlock();
}

bool ThreadSafeSerialShiftRegisterManager::is_high(ssroutputpin pin) {
    m_mutex.lock();

    bool result = m_manager->is_high(pin);

    m_mutex.unlock();

    return result;
}

