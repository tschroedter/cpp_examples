/*
 * ThreadSafe74HC595.h
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_THREADSAFE_THREADSAFE74HC595_H_
#define HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_THREADSAFE_THREADSAFE74HC595_H_

#include <mutex>
#include "Common/CommonTypes.h"
#include "Hardware/Interfaces/IO/SerialShiftRegister/I74HC595.h"
#include "../../../Interfaces/IO/SerialShiftRegister/ThreadSafe/IThreadSafe74HC595.h"

namespace Hardware {
namespace Abstract {
namespace IO {
namespace SerialShiftRegister {
namespace ThreadSafe {
class ThreadSafe74HC595 :
        public Hardware::Abstract::Interfaces::IO::SerialShiftRegister::ThreadSafe::IThreadSafe74HC595 {
 public:
    ThreadSafe74HC595(I74HC595_SPtr ssr);
    virtual ~ThreadSafe74HC595() = default;

    wiringpipin get_pin_ds() const override;
    wiringpipin get_pin_st_cp() const override;
    wiringpipin get_pin_sh_cp() const override;
    void initialize(wiringpipin pin_ds, wiringpipin pin_sh_dp,
                    wiringpipin pin_sh_cp) override;
    void set_value(int value) override;
    int get_value() override;

 private:
    I74HC595_SPtr m_ssr;
    std::recursive_mutex m_mutex { };
};
}
}
}
}
}

#endif /* HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_THREADSAFE74HC595_H_ */
