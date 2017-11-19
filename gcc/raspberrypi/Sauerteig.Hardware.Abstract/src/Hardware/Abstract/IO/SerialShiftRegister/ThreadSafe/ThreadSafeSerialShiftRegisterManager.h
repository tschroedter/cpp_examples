/*
 * ThreadSafeSerialShiftRegisterManager.h
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_THREADSAFE_THREADSAFESERIALSHIFTREGISTERMANAGER_H_
#define HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_THREADSAFE_THREADSAFESERIALSHIFTREGISTERMANAGER_H_

#include <mutex>
#include "../../../Interfaces/IO/SerialShiftRegister/ISerialShiftRegisterManager.h"
#include "../../../Interfaces/IO/SerialShiftRegister/ThreadSafe/IThreadSafeSerialShiftRegisterManager.h"

namespace Hardware {
namespace Abstract {
namespace IO {
namespace SerialShiftRegister {
namespace ThreadSafe {
class ThreadSafeSerialShiftRegisterManager :
        public Hardware::Abstract::Interfaces::IO::SerialShiftRegister::ThreadSafe::IThreadSafeSerialShiftRegisterManager {
 public:
    ThreadSafeSerialShiftRegisterManager(
            ISerialShiftRegisterManager_SPtr manager);
    virtual ~ThreadSafeSerialShiftRegisterManager() = default;

    void initialize(wiringpipin pin_ds, wiringpipin pin_sh_dp,
                    wiringpipin pin_sh_cp) override;
    void high(ssroutputpin pin) override;
    void low(ssroutputpin pin) override;
    bool is_high(ssroutputpin pin) override;

 private:
    ISerialShiftRegisterManager_SPtr m_manager;
    std::recursive_mutex m_mutex { };
};
}
}
}
}
}

#endif /* HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_THREADSAFE_THREADSAFESERIALSHIFTREGISTERMANAGER_H_ */
