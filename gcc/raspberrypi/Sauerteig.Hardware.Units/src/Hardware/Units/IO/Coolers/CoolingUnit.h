/*
 * HeatingUnit.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_IO_COOLERS_HEATINGUNIT_H_
#define SRC_HARDWARE_UNITS_IO_COOLERS_HEATINGUNIT_H_

#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/IO/Coolers/ICooler.h"
#include "../../Interfaces/IO/Coolers/ICoolerLED.h"
#include "../../Interfaces/IO/Coolers/ICoolingUnit.h"

namespace Hardware {
namespace Units {
namespace IO {
namespace Coolers {
class CoolingUnit : public Hardware::Units::Interfaces::IO::Coolers::ICoolingUnit {
 public:
    CoolingUnit(ILogger_SPtr logger, ICooler_SPtr cooler, ICoolerLED_SPtr led);
    virtual ~CoolingUnit() = default;

    // ISwitchable
    void on() override;
    void off() override;
    bool is_on() const override;

 private:
    ILogger_SPtr m_logger = nullptr;
    ICooler_SPtr m_cooler = nullptr;
    ICoolerLED_SPtr m_led = nullptr;
};
}
}
}
}

#endif /* SRC_HARDWARE_UNITS_IO_COOLERS_HEATINGUNIT_H_ */
