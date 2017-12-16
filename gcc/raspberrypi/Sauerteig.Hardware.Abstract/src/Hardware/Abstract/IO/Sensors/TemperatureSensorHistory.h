/*
 * TemperatureSensorHistory.h
 *
 *  Created on: 21 Nov. 2017
 *      Author: tom
 */

#ifndef MONITORS_TEMPERATURESENSORHISTORY_H_
#define MONITORS_TEMPERATURESENSORHISTORY_H_

#include <deque>
#include "Common/CommonTypes.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensorHistory.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensorHistoryData.h"

using namespace Hardware::Abstract::Interfaces::IO::Sensors;

namespace Hardware {
namespace Abstract {
namespace IO {
namespace Sensors {
class TemperatureSensorHistory : public ITemperatureSensorHistory {
 public:
    TemperatureSensorHistory() = default;
    virtual ~TemperatureSensorHistory() = default;

    void push_back(ITemperatureSensorHistoryData_SPtr data) override;
    void pop_front() override;
    size_t size() const override;
    ITemperatureSensorHistoryData_SPtr get_element_at(uint index) const
            override;
    void set_number_of_samples(uint number_of_samples) override;
    uint get_number_of_samples() const override;
    void clear() override;

 private:
    uint m_number_of_samples = 10;
    std::deque<ITemperatureSensorHistoryData_SPtr> m_past_data { };
};
}
}
}
}

#endif /* MONITORS_TEMPERATURESENSORHISTORY_H_ */
