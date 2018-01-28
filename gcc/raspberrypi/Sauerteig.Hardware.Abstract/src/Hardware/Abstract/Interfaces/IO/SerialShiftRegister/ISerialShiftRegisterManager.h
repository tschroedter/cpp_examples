/*
 * ISerialShiftRegister.h
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_SERIALSHIFTREGISTER_ISERIALSHIFTREGISTERMANAGER_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_SERIALSHIFTREGISTER_ISERIALSHIFTREGISTERMANAGER_H_

#include <memory>
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace SerialShiftRegister {
class ISerialShiftRegisterManager {
 public:
    virtual ~ISerialShiftRegisterManager() = default;

    virtual void initialize(wiringpipin pin_ds, wiringpipin pin_sh_dp, wiringpipin pin_sh_cp) = 0;
    virtual void high(ssroutputpin pin) = 0;
    virtual void low(ssroutputpin pin) = 0;
    virtual bool is_high(ssroutputpin pin) const = 0;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::SerialShiftRegister::ISerialShiftRegisterManager> ISerialShiftRegisterManager_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_SERIALSHIFTREGISTER_ISERIALSHIFTREGISTERMANAGER_H_ */
