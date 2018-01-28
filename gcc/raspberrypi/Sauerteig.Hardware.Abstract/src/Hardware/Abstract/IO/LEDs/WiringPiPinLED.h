/*
 * LED.h
 *
 *  Created on: 8 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_IO_LED_WIRINGPIPINLED_H_
#define SRC_HARDWARE_IO_LED_WIRINGPIPINLED_H_

#include "../../Interfaces/IO/LEDs/IWiringPiPinLED.h"
#include "../../Interfaces/IO/IWiringPiPin.h"
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace IO {
namespace LEDs {
class WiringPiPinLED : public Hardware::Abstract::Interfaces::IO::LEDs::IWiringPiPinLED {
 public:
    WiringPiPinLED(IWiringPiPin_SPtr pin);
    virtual ~WiringPiPinLED() = default;

    // IWiringPiPinLED
    void initialize(uint wiring_pi_pin) override;

    // ISwitchable
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

#endif /* SRC_HARDWARE_IO_LED_WIRINGPIPINLED_H_ */
