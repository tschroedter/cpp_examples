/*
 * WiringPiPinHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_IO_COOLERS_WIRINGPIPINCOOLER_H_
#define SRC_HARDWARE_UNITS_IO_COOLERS_WIRINGPIPINCOOLER_H_

#include "../../Interfaces/IO/Coolers/IWiringPiPinCooler.h"
#include "Hardware/Abstract/Interfaces/IO/IWiringPiPin.h"
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Units {
namespace IO {
namespace Coolers {
class WiringPiPinCooler : public Hardware::Units::Interfaces::IO::Coolers::IWiringPiPinCooler {
 public:
    WiringPiPinCooler(IWiringPiPin_SPtr pin);
    virtual ~WiringPiPinCooler() = default;

    void initialize(wiringpipin wiring_pi_pin) override;

    void on() override;
    void off() override;
    bool is_on() const override;

 private:
    IWiringPiPin_SPtr m_pin = nullptr;
};
}
}
}
}

#endif /* SRC_HARDWARE_UNITS_IO_COOLERS_WIRINGPIPINCOOLER_H_ */
