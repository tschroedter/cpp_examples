/*
 * SSR74HC595.h
 *
 *  Created on: 7 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_IO_SERIALSHIFTREGISTER_SSR74HC595_H_
#define SRC_HARDWARE_IO_SERIALSHIFTREGISTER_SSR74HC595_H_

#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/IO/SerialShiftRegister/I74HC595.h"

using namespace Hardware::Interfaces::IO::SerialShiftRegister;

namespace Hardware {
namespace IO {
namespace SerialShiftRegisters {
class SSR74HC595 : public I74HC595 {
 public:
    SSR74HC595(ILogger_SPtr logger);
    virtual ~SSR74HC595() = default;

    wiringpipin get_pin_ds() const override;
    wiringpipin get_pin_st_cp() const override;
    wiringpipin get_pin_sh_cp() const override;
    void initialize(wiringpipin pin_ds, wiringpipin pin_sh_cp, wiringpipin pin_sh_dp) override;

    void set_value(int value) override;
    int get_value() const override;

 private:
    ILogger_SPtr m_logger = nullptr;
    wiringpipin m_pin_ds;
    wiringpipin m_pin_st_cp;
    wiringpipin m_pin_sh_cp;
    int m_value;

    void write_value();
};
}
}
}

#endif /* SRC_HARDWARE_IO_SERIALSHIFTREGISTER_SSR74HC595_H_ */
