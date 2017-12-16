/*
 * TemperatureSensorHistoryData.h
 *
 *  Created on: 21 Nov. 2017
 *      Author: tom
 */

#ifndef MONITORS_TEMPERATURESENSORHISTORYDATA_H_
#define MONITORS_TEMPERATURESENSORHISTORYDATA_H_

#include "Common/CommonTypes.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensorHistoryData.h"

using namespace Hardware::Abstract::Interfaces::IO::Sensors;

namespace Hardware {
namespace Abstract {
namespace IO {
namespace Sensors {
class TemperatureSensorHistoryData : public ITemperatureSensorHistoryData {
 public:
    TemperatureSensorHistoryData() = default;
    virtual ~TemperatureSensorHistoryData() = default;

    void set_value(celsius value) override;
    void set_is_valid(bool is_valid) override;
    celsius get_value() const override;
    bool is_valid() const override;

 private:
    celsius m_value = 0;
    bool m_is_valid = false;
};
}
}
}
}

#endif /* MONITORS_TEMPERATURESENSORHISTORYDATA_H_ */
