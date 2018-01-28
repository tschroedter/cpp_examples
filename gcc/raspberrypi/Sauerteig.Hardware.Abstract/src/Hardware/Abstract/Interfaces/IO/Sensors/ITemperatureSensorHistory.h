/*
 * ITemperatureSensorHistory.h
 *
 *  Created on: 21 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURESENSORHISTORY_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURESENSORHISTORY_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "ITemperatureSensorHistoryData.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace Sensors {
class ITemperatureSensorHistory {
 public:
    virtual ~ITemperatureSensorHistory() = default;
    virtual void push_back(ITemperatureSensorHistoryData_SPtr data) = 0;
    virtual void pop_front() = 0;
    virtual size_t size() const = 0;
    virtual ITemperatureSensorHistoryData_SPtr get_element_at(uint index) const = 0;
    virtual void set_number_of_samples(uint number_of_samples) = 0;
    virtual uint get_number_of_samples() const = 0;
    virtual void clear() = 0;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::Sensors::ITemperatureSensorHistory> ITemperatureSensorHistory_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_SENSORS_ITEMPERATURESENSORHISTORY_H_ */
