/*
 * Heater.h
 *
 *  Created on: 23 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_UNITS_IO_HEATERS_HEATER_H_
#define HARDWARE_UNITS_IO_HEATERS_HEATER_H_

#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/IO/Heaters/IHeater.h"
#include "../../Interfaces/IO/Heaters/ISSRHeater.h"

namespace Hardware {
namespace Units {
namespace IO {
namespace Heaters {
class Heater : public Hardware::Units::Interfaces::IO::Heaters::IHeater {
 public:
    Heater(ILogger_SPtr logger, ISSRHeater_SPtr heater);
    virtual ~Heater() = default;

    // ISwitchable
    void on() override;
    void off() override;
    bool is_on() const override;

 private:
    ILogger_SPtr m_logger = nullptr;
    ISSRHeater_SPtr m_heater = nullptr;
};
}
}
}
}

#endif /* HARDWARE_UNITS_IO_HEATERS_HEATER_H_ */
