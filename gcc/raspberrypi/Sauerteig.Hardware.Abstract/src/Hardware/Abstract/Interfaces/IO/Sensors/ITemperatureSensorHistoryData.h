/*
 * ITemperatureSensorHistoryData.h
 *
 *  Created on: 21 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURESENSORHISTORYDATA_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURESENSORHISTORYDATA_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "ITemperatureSensorHistoryData.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace Sensors {
class ITemperatureSensorHistoryData {
 public:
    virtual ~ITemperatureSensorHistoryData() = default;

    virtual void set_value(celsius value) = 0;
    virtual void set_is_valid(bool is_valid) = 0;
    virtual celsius get_value() const = 0;
    virtual bool is_valid() const = 0;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::Sensors::ITemperatureSensorHistoryData> ITemperatureSensorHistoryData_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURESENSORHISTORYDATA_H_ */
