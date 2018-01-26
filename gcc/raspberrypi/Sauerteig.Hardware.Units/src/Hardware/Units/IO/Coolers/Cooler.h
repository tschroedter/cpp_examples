/*
 * Heater.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_IO_COOLERS_HEATER_H_
#define SRC_HARDWARE_UNITS_IO_COOLERS_HEATER_H_

#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/IO/Coolers/ICooler.h"
#include "../../Interfaces/IO/Coolers/ISSRCooler.h"

namespace Hardware {
namespace Units {
namespace IO {
namespace Coolers {
class Cooler : public Hardware::Units::Interfaces::IO::Coolers::ICooler {
 public:
    Cooler(ILogger_SPtr logger, ISSRCooler_SPtr cooler);
    virtual ~Cooler() = default;

    // ISwitchable
    void on() override;
    void off() override;
    bool is_on() const override;

 private:
    ILogger_SPtr m_logger = nullptr;
    ISSRCooler_SPtr m_cooler = nullptr;
};
}
}
}
}

#endif /* SRC_HARDWARE_UNITS_IO_COOLERS_HEATER_H_ */
