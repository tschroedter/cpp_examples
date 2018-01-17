/*
 * TemperaturesMessageHandler.h
 *
 *  Created on: 16 Jan. 2018
 *      Author: tom
 */

#ifndef MONITORS_TEMPERATURES_TEMPERATURESMESSAGEHANDLER_H_
#define MONITORS_TEMPERATURES_TEMPERATURESMESSAGEHANDLER_H_

#include <memory.h>
#include <functional>
#include <thread>
#include <chrono>
#include "../../Interfaces/Factories/ITemperaturesMessageBusNodeFactory.h"
#include "../../Interfaces/Monitors/Temperatures/ITemperaturesMessageHandler.h"
#include "../../Messages/TemperaturesMessage.h"
#include "Common/Interfaces/ILogger.h"
#include "TemperaturesMessageBusNode.h"

#define INTERVAL_IN_SECONDS 1

namespace Sauerteig {
namespace Monitors {
namespace Temperatures {

class TemperaturesMessageHandler : public ::Sauerteig::Interfaces::Monitors::Temperatures::ITemperaturesMessageHandler {
 public:
    TemperaturesMessageHandler(ILogger_SPtr logger,
                               ITemperaturesMessageBusNodeFactory_SPtr factory);
    virtual ~TemperaturesMessageHandler() = default;

    celsius get_inside_average_value() const override;
    double get_inside_average__percent_valid() const override;
    celsius get_outside_average_value() const override;
    double get_outside_average__percent_valid() const override;

 private:
    ILogger_SPtr m_logger = nullptr;
    TemperaturesMessageBusNode_SPtr m_bus_node = nullptr;
};

}
}
}

#endif /* MONITORS_TEMPERATURES_TEMPERATURESMESSAGEHANDLER_H_ */
