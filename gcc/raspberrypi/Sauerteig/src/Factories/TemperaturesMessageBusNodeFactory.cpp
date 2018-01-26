/*
 * TemperaturesMessageBusNodeFactory.cpp
 *
 *  Created on: 17 Jan. 2018
 *      Author: tom
 */

#include <memory.h>
#include <string.h>
#include "TemperaturesMessageBusNodeFactory.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "../Monitors/Temperatures/TemperaturesMessageBusNode.h"

using namespace std;
using namespace Common::Exceptions;

namespace Sauerteig {
namespace Factories {

TemperaturesMessageBusNodeFactory::TemperaturesMessageBusNodeFactory(
        ILogger_SPtr logger,
        IBus_SPtr bus)
    : m_logger(logger), m_bus(bus) {
    if (m_logger == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'logger' is null!",
                                                           "logger");
    }

    if (m_bus == nullptr) {
        throw ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'bus' is null!",
                                                           "bus");
    }
}

TemperaturesMessageBusNode_SPtr TemperaturesMessageBusNodeFactory::create(string subscriber_id) {
    auto instance = make_shared<Monitors::Temperatures::TemperaturesMessageBusNode>(m_logger, m_bus, subscriber_id);

    return instance;
}

void TemperaturesMessageBusNodeFactory::release(TemperaturesMessageBusNode_SPtr bus_node) {
}

}
}
