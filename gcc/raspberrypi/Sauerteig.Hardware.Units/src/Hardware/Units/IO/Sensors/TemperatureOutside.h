/*
 * TemperatureOutside.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_IO_SENSORS_TEMPERATUREOUTSIDE_H_
#define SRC_HARDWARE_UNITS_IO_SENSORS_TEMPERATUREOUTSIDE_H_

#include "Common/CommonTypes.h"
#include "../../Interfaces/IO/Sensors/ITemperatureOutside.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/IADCTmp36.h"

using namespace Hardware::Units::Interfaces::IO::Sensors;

namespace Hardware {
namespace Units {
namespace IO {
namespace Sensors {
class TemperatureOutside : public ITemperatureOutside {
 public:
    TemperatureOutside(IADCTmp36_SPtr tmp36);
    virtual ~TemperatureOutside() = default;

    bool is_value_valid() const override;
    celsius get_value() const override;
    void refresh() override;

 private:
    IADCTmp36_SPtr m_tmp36;
};
}
}
}
}

#endif /* SRC_HARDWARE_UNITS_IO_SENSORS_TEMPERATUREOUTSIDE_H_ */
