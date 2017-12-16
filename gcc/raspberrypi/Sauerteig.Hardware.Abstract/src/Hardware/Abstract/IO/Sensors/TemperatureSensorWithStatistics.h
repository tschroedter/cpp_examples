/*
 * TemperatureSensorWithStatistics.h
 *
 *  Created on: 20 Nov. 2017
 *      Author: tom
 */

#ifndef MONITORS_TEMPERATURESENSORWITHSTATISTICS_H_
#define MONITORS_TEMPERATURESENSORWITHSTATISTICS_H_

#include <deque>
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensorWithStatistics.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensorHistory.h"
#include "../../Interfaces/IO/Sensors/ITemperatureSensorHistoryData.h"

using namespace Hardware::Abstract::Interfaces::IO::Sensors;

namespace Hardware {
namespace Abstract {
namespace IO {
namespace Sensors {
class TemperatureSensorWithStatistics : public ITemperatureSensorWithStatistics {
 public:
    TemperatureSensorWithStatistics(ILogger_SPtr logger,
                                    ITemperatureSensorHistory_SPtr history);
    virtual ~TemperatureSensorWithStatistics() = default;

    celsius get_value() const override;
    bool is_value_valid() const override;
    void refresh() override;

    void initialize(ITemperatureSensor_SPtr sensor) override;
    celsius get_average_value() const override;
    double get_average_percent_valid() const override;
    void set_number_of_samples(uint number_of_samples) override;
    uint get_number_of_samples() const override;

 private:
    ILogger_SPtr m_logger = nullptr;
    ITemperatureSensor_SPtr m_sensor = nullptr;
    celsius m_average_temperature = 0.0;
    double m_temperature_valid_percentage = 0.0;
    ITemperatureSensorHistory_SPtr m_history = nullptr;

    void validate_sensor() const;
    void update_statistics();
};
}
}
}
}

#endif /* MONITORS_TEMPERATURESENSORWITHSTATISTICS_H_ */
