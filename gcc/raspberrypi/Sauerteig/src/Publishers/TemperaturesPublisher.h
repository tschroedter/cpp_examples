/*
 * TemperaturesPublisher.h
 *
 *  Created on: 16 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_PUBLISHERS_TEMPERATURESPUBLISHER_H_
#define SRC_PUBLISHERS_TEMPERATURESPUBLISHER_H_

#define INTERVAL_IN_SECONDS 1

#include <thread>
#include <chrono>
#include "Common/Interfaces/ILogger.h"
#include "Hardware/Abstract/Interfaces/IO/Sensors/ITemperatureSensorWithStatistics.h"
#include "Hardware/Units/Interfaces/IO/Sensors/ITemperatureInside.h"
#include "Hardware/Units/Interfaces/IO/Sensors/ITemperatureOutside.h"
#include "InMemoryBus/IBus.h"
#include "Common/Interfaces/IThreadInformationProvider.h"
#include "../Interfaces/Publishers/ITemperaturesPublisher.h"
#include "../Interfaces/ISettings.h"
#include "../Interfaces/Factories/ITemperaturesSetCorrectionMessageBusNodeFactory.h"
#include "../BusNodes/TemperaturesSetCorrectionMessageBusNode.h"

using namespace Sauerteig::Interfaces::Publishers;

namespace Sauerteig {
namespace Publishers {

class TemperaturesPublisher : public ITemperaturesPublisher {
 public:
    // TODO constructor is getting to big
    TemperaturesPublisher(ILogger_SPtr logger, IBus_SPtr bus, IThreadInformationProvider_SPtr provider,
                          ITemperatureInside_SPtr inside, ITemperatureOutside_SPtr outside,
                          ITemperatureSensorWithStatistics_SPtr inside_with_statistics,
                          ITemperatureSensorWithStatistics_SPtr outside_with_statistics,
                          ITemperaturesSetCorrectionMessageBusNodeFactory_SPtr factory);

    virtual ~TemperaturesPublisher() = default;

    void operator()() override {
        std::string pid = m_provider->get_thread_process_id_as_string();
        m_logger->info("TemperaturesPublisher PID: " + pid);

        while (1) {
            std::this_thread::sleep_for(std::chrono::seconds(INTERVAL_IN_SECONDS));

            publish();
        }
    }

    void publish() override;

 private:
    ILogger_SPtr m_logger = nullptr;
    IBus_SPtr m_bus = nullptr;
    IThreadInformationProvider_SPtr m_provider = nullptr;
    ITemperatureSensorWithStatistics_SPtr m_inside = nullptr;
    ITemperatureSensorWithStatistics_SPtr m_outside = nullptr;
    TemperaturesSetCorrectionMessageBusNode_SPtr m_bus_node = nullptr;
};

}
}

#endif /* SRC_PUBLISHERS_TEMPERATURESPUBLISHER_H_ */
