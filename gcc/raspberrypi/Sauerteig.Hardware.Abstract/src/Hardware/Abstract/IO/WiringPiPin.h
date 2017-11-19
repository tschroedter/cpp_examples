/*
 * WiringPiPin.h
 *
 *  Created on: 11 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_IO_WIRINGPIPIN_H_
#define SRC_HARDWARE_ABSTRACT_IO_WIRINGPIPIN_H_

#include "wiringPi.h"
#include "../Interfaces/IO/IWiringPiPin.h"
#include "Common/CommonTypes.h"

using namespace Hardware::Abstract;

namespace Hardware {
namespace Abstract {
namespace IO {
class WiringPiPin : public Interfaces::IO::IWiringPiPin {
 public:
    WiringPiPin() = default;
    virtual ~WiringPiPin() = default;

    void initialize(uint wiring_pi_pin, uint pin_mode) override;
    uint get_pin() const override;
    void set_mode(uint mode) override;
    uint get_mode() const override;
    void high() override;
    void low() override;
    bool is_high() const override;

 private:
    uint m_pin = 0;
    uint m_mode = OUTPUT;
    bool m_is_high = false;
};
}
}
}

#endif /* SRC_HARDWARE_ABSTRACT_IO_WIRINGPIPIN_H_ */
