/*
 * TemperaturesSetCorrectionMessageHandler.h
 *
 *  Created on: 6 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_MONITORS_SETTINGS_TEMPERATURESSETCORRECTIONMESSAGEHANDLER_H_
#define SRC_MONITORS_SETTINGS_TEMPERATURESSETCORRECTIONMESSAGEHANDLER_H_

#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/Factories/ITemperaturesSetCorrectionMessageBusNodeFactory.h"
#include "../../Interfaces/Monitors/Settings/ITemperaturesSetCorrectionMessageHandler.h"
#include "../../BusNodes/TemperaturesSetCorrectionMessageBusNode.h"

#define TEMPERATURESSETCORRECTIONMESSAGEHANDLER_SUBSCRIBER_ID "TemperaturesSetCorrectionMessageHandler"

using namespace Sauerteig::Interfaces::Monitors::Settings;

namespace Sauerteig {
namespace Monitors {
namespace Settings {

class TemperaturesSetCorrectionMessageHandler : public ITemperaturesSetCorrectionMessageHandler {
 public:
    TemperaturesSetCorrectionMessageHandler(ILogger_SPtr logger,
                                            ITemperaturesSetCorrectionMessageBusNodeFactory_SPtr factory);
    virtual ~TemperaturesSetCorrectionMessageHandler() = default;

    celsius get_inside_average_value_correction() const override;
    celsius get_outside_average_value_correction() const override;

 private:
    ILogger_SPtr m_logger = nullptr;
    TemperaturesSetCorrectionMessageBusNode_SPtr m_bus_node = nullptr;
};

}
}
}

#endif /* SRC_MONITORS_SETTINGS_TEMPERATURESSETCORRECTIONMESSAGEHANDLER_H_ */
