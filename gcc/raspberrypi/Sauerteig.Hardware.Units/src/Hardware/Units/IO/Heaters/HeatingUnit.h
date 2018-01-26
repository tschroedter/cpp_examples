/*
 * HeatingUnit.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef SCR_HARDWARE_UNITS_IO_HEATERS_HEATINGUNIT_H_
#define SCR_HARDWARE_UNITS_IO_HEATERS_HEATINGUNIT_H_

#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/IO/Heaters/IHeatingUnit.h"
#include "../../Interfaces/IO/Heaters/IHeater.h"
#include "../../Interfaces/IO/Heaters/IHeaterLED.h"

namespace Hardware {
namespace Units {
namespace IO {
namespace Heaters {
class HeatingUnit : public Hardware::Units::Interfaces::IO::Heaters::IHeatingUnit {
 public:
    HeatingUnit(ILogger_SPtr logger, IHeater_SPtr heater, IHeaterLED_SPtr led);
    virtual ~HeatingUnit() = default;

    // ISwitchable
    void on() override;
    void off() override;
    bool is_on() const override;

 private:
    ILogger_SPtr m_logger = nullptr;
    IHeater_SPtr m_heater = nullptr;
    IHeaterLED_SPtr m_led = nullptr;
};
}
}
}
}

#endif /* SCR_HARDWARE_UNITS_IO_HEATERS_HEATINGUNIT_H_ */
