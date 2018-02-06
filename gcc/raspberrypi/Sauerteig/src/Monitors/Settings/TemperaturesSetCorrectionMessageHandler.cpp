/*
 * TemperaturesSetCorrectionMessageHandler.cpp
 *
 *  Created on: 6 Feb. 2018
 *      Author: tom
 */

#include "TemperaturesSetCorrectionMessageHandler.h"
#include "Common/CommonTypes.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/Factories/ITemperaturesSetCorrectionMessageBusNodeFactory.h"

using namespace Common::Exceptions;

namespace Sauerteig {
namespace Monitors {
namespace Settings {

TemperaturesSetCorrectionMessageHandler::TemperaturesSetCorrectionMessageHandler(
        ILogger_SPtr logger,
        ITemperaturesSetCorrectionMessageBusNodeFactory_SPtr factory)
    : m_logger(logger) {
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageHandler because 'logger' is null!", "logger");
    }

    if (factory == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageHandler because 'factory' is null!",
                                       "factory");
    }

    m_bus_node = factory->create(TEMPERATURESSETCORRECTIONMESSAGEHANDLER_SUBSCRIBER_ID);

    if (m_bus_node == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageHandler because 'bus_node' is null!",
                                       "bus_node");
    }

    m_logger->set_prefix("TemperaturesSetCorrectionMessageHandler");
}

celsius TemperaturesSetCorrectionMessageHandler::get_inside_average_value_correction() const {
    return m_bus_node->get_inside_average_value_correction();
}

celsius TemperaturesSetCorrectionMessageHandler::get_outside_average_value_correction() const {
    return m_bus_node->get_inside_average_value_correction();
}

}
}
}
