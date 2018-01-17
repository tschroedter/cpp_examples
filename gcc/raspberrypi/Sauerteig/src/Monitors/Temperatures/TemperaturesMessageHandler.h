/*
 * TemperaturesMessageHandler.h
 *
 *  Created on: 16 Jan. 2018
 *      Author: tom
 */

#ifndef MONITORS_TEMPERATURES_TEMPERATURESMESSAGEHANDLER_H_
#define MONITORS_TEMPERATURES_TEMPERATURESMESSAGEHANDLER_H_

#include <memory.h>
#include <thread>
#include <chrono>
#include "../../Interfaces/Monitors/Temperatures/ITemperaturesMessageHandler.h"
#include "../../Messages/TemperaturesMessage.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "TemperaturesMessageBusNode.h"

#define INTERVAL_IN_SECONDS 1

namespace Sauerteig {
namespace Monitors {
namespace Temperatures {

class TemperaturesMessageHandler : public ::Sauerteig::Interfaces::Monitors::Temperatures::ITemperaturesMessageHandler {
 public:
    TemperaturesMessageHandler(ILogger_SPtr logger, IBus_SPtr bus);
    virtual ~TemperaturesMessageHandler() = default;

    void operator()() override {
        while (1) {
            std::this_thread::sleep_for(std::chrono::seconds(INTERVAL_IN_SECONDS));

            m_logger->info(to_string());
        }
    }

    std::string to_string();

 private:
    ILogger_SPtr m_logger = nullptr;
    IBus_SPtr m_bus = nullptr;
    TemperaturesMessageBusNode_SPtr m_bus_node = nullptr;
};

}
}
}

#endif /* MONITORS_TEMPERATURES_TEMPERATURESMESSAGEHANDLER_H_ */
