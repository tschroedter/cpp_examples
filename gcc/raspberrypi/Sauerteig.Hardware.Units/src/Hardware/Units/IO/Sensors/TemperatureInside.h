/*
 * TemperatureInside.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_IO_SENSORS_TEMPERATUREINSIDE_H_
#define SRC_HARDWARE_UNITS_IO_SENSORS_TEMPERATUREINSIDE_H_

#include "Common/CommonTypes.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/IADCTmp36.h"
#include "../../Interfaces/IO/Sensors/ITemperatureInside.h"

using namespace Hardware::Units::Interfaces::IO::Sensors;

namespace Hardware {
namespace Units {
namespace IO {
namespace Sensors {
class TemperatureInside : public ITemperatureInside {
 public:
    TemperatureInside(IADCTmp36_SPtr tmp36);
    virtual ~TemperatureInside() = default;

    celsius get_value() const override;
    bool is_value_valid() const override;
    void refresh() override;

 private:
    IADCTmp36_SPtr m_tmp36;
};
}
}
}
}

#endif /* SRC_HARDWARE_UNITS_IO_SENSORS_TEMPERATUREINSIDE_H_ */
