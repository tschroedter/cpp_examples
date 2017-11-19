/*
 * IThreadSafe74HC595.h
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_SERIALSHIFTREGISTER_THREADSAFE_ITHREADSAFE74HC595_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_SERIALSHIFTREGISTER_THREADSAFE_ITHREADSAFE74HC595_H_

#include <memory>
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace SerialShiftRegister {
namespace ThreadSafe {
class IThreadSafe74HC595 {
 public:
    virtual ~IThreadSafe74HC595() = default;

    virtual wiringpipin get_pin_ds() const = 0;
    virtual wiringpipin get_pin_st_cp() const = 0;
    virtual wiringpipin get_pin_sh_cp() const = 0;
    virtual void initialize(wiringpipin pin_ds, wiringpipin pin_sh_dp,
                            wiringpipin pin_sh_cp) = 0;
    virtual void set_value(int value) = 0;
    virtual int get_value() = 0;
};
}
}
}
}
}
}

typedef std::shared_ptr<
        Hardware::Abstract::Interfaces::IO::SerialShiftRegister::ThreadSafe::IThreadSafe74HC595> IThreadSafe74HC595_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_SERIALSHIFTREGISTER_THREADSAFE_ITHREADSAFE74HC595_H_ */
