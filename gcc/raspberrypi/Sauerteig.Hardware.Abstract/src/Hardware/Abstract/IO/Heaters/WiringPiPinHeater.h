/*
 * WiringPiPinHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_IO_HEATERS_WIRINGPIPINHEATER_H_
#define HARDWARE_ABSTRACT_IO_HEATERS_WIRINGPIPINHEATER_H_

#include "../../Interfaces/IO/Heaters/IWiringPiPinHeater.h"
#include "../../Interfaces/IO/IWiringPiPin.h"
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace IO {
namespace Heaters {
class WiringPiPinHeater :
        public Hardware::Abstract::Interfaces::IO::Heaters::IWiringPiPinHeater {
 public:
    WiringPiPinHeater(IWiringPiPin_SPtr pin);
    virtual ~WiringPiPinHeater() = default;

    void initialize(wiringpipin wiring_pi_pin) override;

    void on() override;
    void off() override;
    bool is_on() const override;

 private:
    IWiringPiPin_SPtr m_pin;
};
}
}
}
}

#endif /* HARDWARE_ABSTRACT_IO_HEATERS_WIRINGPIPINHEATER_H_ */
