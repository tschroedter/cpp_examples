/*
 * ITmp36.h
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_INTERFACES_IO_SENSORS_ITMP36_H_
#define SRC_HARDWARE_INTERFACES_IO_SENSORS_ITMP36_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "../../../Interfaces/IO/AnalogeDigitalConverters/IADC.h"

namespace Hardware {
namespace Interfaces {
namespace IO {
namespace Sensors {
class ITmp36 {
 public:
    virtual ~ITmp36() = default;

    virtual void initialize(IADC_SPtr adc, adcchannel channel) = 0;
    virtual bool is_value_valid() const = 0;
    virtual celsius get_value() const = 0;
    virtual uint get_value_raw() const = 0;
    virtual void refresh() = 0;
};
}
}
}
}

typedef std::shared_ptr<Hardware::Interfaces::IO::Sensors::ITmp36> ITmp36_SPtr;

#endif /* SRC_HARDWARE_INTERFACES_IO_SENSORS_ITMP36_H_ */
