/*
 * TemperatureOutside.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_IO_SENSORS_TEMPERATUREOUTSIDE_H_
#define SRC_HARDWARE_ABSTRACT_IO_SENSORS_TEMPERATUREOUTSIDE_H_

#include "Common/CommonTypes.h"
#include "../../Interfaces/IO/Sensors/ITemperatureOutside.h"
#include "../../Interfaces/IO/Sensors/IADCTmp36.h"

namespace Hardware {
namespace Abstract {
namespace IO {
namespace Sensors {
class TemperatureOutside :
        public Hardware::Abstract::Interfaces::IO::Sensors::ITemperatureOutside {
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

#endif /* SRC_HARDWARE_ABSTRACT_IO_SENSORS_TEMPERATUREOUTSIDE_H_ */
