/*
 * SSRLEDFlashing.h
 *
 *  Created on: 16 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_IO_LEDS_SSRLEDFLASHING_H_
#define HARDWARE_ABSTRACT_IO_LEDS_SSRLEDFLASHING_H_

#include "Common/CommonTypes.h"
#include "../../Interfaces/IO/ISwitchableFlashingServer.h"
#include "../../Interfaces/IO/LEDs/ISSRLED.h"
#include "../../Interfaces/IO/LEDs/ISSRLEDFlashing.h"

namespace Hardware {
namespace Abstract {
namespace IO {
namespace LEDs {
class SSRLEDFlashing : public Hardware::Abstract::Interfaces::IO::LEDs::ISSRLEDFlashing {
 public:
    SSRLEDFlashing(ISSRLED_SPtr led, ISwitchableFlashingServer_SPtr server);
    virtual ~SSRLEDFlashing() = default;

    // ISSRLED
    void initialize(ssroutputpin pin) override;

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
    ISSRLED_SPtr m_led = nullptr;
    ISwitchableFlashingServer_SPtr m_server = nullptr;
};
}
}
}
}

#endif /* HARDWARE_ABSTRACT_IO_LEDS_SSRLEDFLASHING_H_ */
