/*
 * HeaterLed.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_IO_COOLERS_HEATERLED_H_
#define SRC_HARDWARE_UNITS_IO_COOLERS_HEATERLED_H_

#include "../../Interfaces/IO/Coolers/ICoolerLED.h"
#include "Hardware/Abstract/Interfaces/IO/LEDs/ISSRLEDFlashing.h"

namespace Hardware {
namespace Units {
namespace IO {
namespace Coolers {
class CoolerLED : public Hardware::Units::Interfaces::IO::Coolers::ICoolerLED {
 public:
    CoolerLED(ISSRLEDFlashing_SPtr led);  // TODO rename ISSRLEDFlashing_SPtr to ISSRLEDFlashable
    virtual ~CoolerLED() = default;

    // ISwitchable
    void on() override;
    void off() override;
    bool is_on() const override;

    // IFlashable
    void start() override;
    void stop() override;
    void set_on_interval_in_msec(uint interval) override;
    void set_off_interval_in_msec(uint interval) override;
    uint get_on_interval_in_msec() override;
    uint get_off_interval_in_msec() override;
    bool is_flashing_enable() const override;

 private:
    ISSRLEDFlashing_SPtr m_led = nullptr;
};
}
}
}
}

#endif /* SRC_HARDWARE_UNITS_IO_COOLERS_HEATERLED_H_ */
