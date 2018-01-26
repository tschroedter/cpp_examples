/*
 * HeaterLed.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef SCR_HARDWARE_UNITS_IO_HEATERS_HEATERLED_H_
#define SCR_HARDWARE_UNITS_IO_HEATERS_HEATERLED_H_

#include "../../Interfaces/IO/Heaters/IHeaterLED.h"
#include "Hardware/Abstract/Interfaces/IO/LEDs/ISSRLEDFlashing.h"

namespace Hardware {
namespace Units {
namespace IO {
namespace Heaters {
class HeaterLED : public Hardware::Units::Interfaces::IO::Heaters::IHeaterLED {
 public:
    HeaterLED(ISSRLEDFlashing_SPtr led);  // TODO rename ISSRLEDFlashing_SPtr to ISSRLEDFlashable
    virtual ~HeaterLED() = default;

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

#endif /* SCR_HARDWARE_UNITS_IO_HEATERS_HEATERLED_H_ */
