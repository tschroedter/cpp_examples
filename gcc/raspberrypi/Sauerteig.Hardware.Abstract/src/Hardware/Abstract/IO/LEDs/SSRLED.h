/*
 * SSRLED.h
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_IO_LEDS_SSRLED_H_
#define HARDWARE_ABSTRACT_IO_LEDS_SSRLED_H_

#include "../../Interfaces/IO/LEDs/ISSRLED.h"
#include "../../Interfaces/IO/SerialShiftRegister/ISSROutputs.h"
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace IO {
namespace LEDs {
class SSRLED : public Hardware::Abstract::Interfaces::IO::LEDs::ISSRLED {
 public:
    SSRLED(ISSROutputs_SPtr ssr);
    virtual ~SSRLED() = default;

    // ISSRLED
    void initialize(ssroutputpin pin) override;

    // ISwitchable
    void on() override;
    void off() override;
    bool is_on() const override;

 private:
    ISSROutputs_SPtr m_ssr;
    ssroutputpin m_pin = 0;
};
}
}
}
}

#endif /* HARDWARE_ABSTRACT_IO_LEDS_SSRLED_H_ */
