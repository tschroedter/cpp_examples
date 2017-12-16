/*
 * I74HC595.h
 *
 *  Created on: 7 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_INTERFACES_IO_SERIALSHIFTREGISTER_I74HC595_H_
#define SRC_HARDWARE_INTERFACES_IO_SERIALSHIFTREGISTER_I74HC595_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "ISSR.h"

namespace Hardware {
namespace Interfaces {
namespace IO {
namespace SerialShiftRegister {
class I74HC595 : public ISSR {
 public:
    virtual ~I74HC595() = default;

    virtual wiringpipin get_pin_ds() const = 0;
    virtual wiringpipin get_pin_st_cp() const = 0;
    virtual wiringpipin get_pin_sh_cp() const = 0;
    virtual void initialize(wiringpipin pin_ds, wiringpipin pin_sh_dp, wiringpipin pin_sh_cp) = 0;
    virtual void set_value(int value) = 0;
    virtual int get_value() const = 0;
};
}
}
}
}

typedef std::shared_ptr<Hardware::Interfaces::IO::SerialShiftRegister::I74HC595> I74HC595_SPtr;

#endif /* SRC_HARDWARE_INTERFACES_IO_SERIALSHIFTREGISTER_I74HC595_H_ */
