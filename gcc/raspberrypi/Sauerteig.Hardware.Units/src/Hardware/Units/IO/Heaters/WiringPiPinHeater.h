/*
 * WiringPiPinHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef SCR_HARDWARE_UNITS_IO_HEATERS_WIRINGPIPINHEATER_H_
#define SCR_HARDWARE_UNITS_IO_HEATERS_WIRINGPIPINHEATER_H_

#include "../../Interfaces/IO/Heaters/IWiringPiPinHeater.h"
#include "Hardware/Abstract/Interfaces/IO/IWiringPiPin.h"
#include "Common/CommonTypes.h"

using namespace Hardware::Units::Interfaces::IO::Heaters;

namespace Hardware {
namespace Units {
namespace IO {
namespace Heaters {
class WiringPiPinHeater : public IWiringPiPinHeater {
 public:
    WiringPiPinHeater(IWiringPiPin_SPtr pin);
    virtual ~WiringPiPinHeater() = default;

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

#endif /* SCR_HARDWARE_UNITS_IO_HEATERS_WIRINGPIPINHEATER_H_ */
