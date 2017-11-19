/*
 * OutputManager.cpp
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#include "SSROutputs.h"

#include "Common/CommonTypes.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Interfaces/IO/SerialShiftRegister/ThreadSafe/IThreadSafeSerialShiftRegisterManager.h"

#define DEFAULT_PIN_DS      ((wiringpipin) 27)
#define DEFAULT_PIN_SH_CP   ((wiringpipin) 29)
#define DEFAULT_PIN_ST_CP   ((wiringpipin) 28)

using namespace Hardware::Abstract::IO::SerialShiftRegister;

SSROutputs::SSROutputs(IThreadSafeSerialShiftRegisterManager_SPtr manager)
        : m_manager(manager) {
    if (m_manager == nullptr) {
        throw Common::Exceptions::ArgumentInvalidException(
                "Can't create SSROutputs because 'm_manager' is null!",
                "m_manager");
    }

    m_manager->initialize(DEFAULT_PIN_DS, DEFAULT_PIN_SH_CP, DEFAULT_PIN_ST_CP);  // TODO set with number of bit Q0-Q7 = 8 bits
}

void SSROutputs::high(ssroutputpin pin) {  // TODO check pin not bigger than number of data pins
    m_manager->high(pin);
}

void SSROutputs::low(ssroutputpin pin) {
    m_manager->low(pin);
}

bool SSROutputs::is_high(ssroutputpin pin) const {
    bool result = m_manager->is_high(pin);

    return result;
}
