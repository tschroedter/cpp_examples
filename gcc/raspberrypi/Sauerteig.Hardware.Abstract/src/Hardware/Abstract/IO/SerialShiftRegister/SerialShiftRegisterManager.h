/*
 * SerialShiftRegisterManager.h
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_SERIALSHIFTREGISTERMANAGER_H_
#define HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_SERIALSHIFTREGISTERMANAGER_H_

#include "Common/CommonTypes.h"
#include "../../Interfaces/IO/SerialShiftRegister/ThreadSafe/IThreadSafe74HC595.h"
#include "../../Interfaces/IO/SerialShiftRegister/ISerialShiftRegisterManager.h"

namespace Hardware {
namespace Abstract {
namespace IO {
namespace SerialShiftRegister {
class SerialShiftRegisterManager :
        public Hardware::Abstract::Interfaces::IO::SerialShiftRegister::ISerialShiftRegisterManager {
 public:
    SerialShiftRegisterManager(IThreadSafe74HC595_SPtr ssr);
    virtual ~SerialShiftRegisterManager() = default;

    void initialize(wiringpipin pin_ds, wiringpipin pin_sh_dp, wiringpipin pin_sh_cp) override;
    void high(ssroutputpin pin) override;
    void low(ssroutputpin pin) override;
    bool is_high(ssroutputpin pin) const override;

 private:
    IThreadSafe74HC595_SPtr m_ssr;
};
}
}
}
}

#endif /* HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_SERIALSHIFTREGISTERMANAGER_H_ */
