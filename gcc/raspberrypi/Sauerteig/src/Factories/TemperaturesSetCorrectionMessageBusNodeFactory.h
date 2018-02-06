/*
 * TemperaturesSetCorrectionMessageBusNodeFactory.h
 *
 *  Created on: 2 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_FACTORIES_TEMPERATURESSETCORRECTIONMESSAGEBUSNODEFACTORY_H_
#define SRC_FACTORIES_TEMPERATURESSETCORRECTIONMESSAGEBUSNODEFACTORY_H_

#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "InMemoryBus/IBus.h"
#include "../Settings.h"
#include "../Interfaces/Factories/ITemperaturesSetCorrectionMessageBusNodeFactory.h"
#include "../Interfaces/ISettings.h"

using namespace std;
using namespace Common::Exceptions;
using namespace InMemoryBus::Common;
using namespace Sauerteig::Interfaces::Factories;

namespace Sauerteig {
namespace Factories {

class TemperaturesSetCorrectionMessageBusNodeFactory : public ITemperaturesSetCorrectionMessageBusNodeFactory {
 public:
    TemperaturesSetCorrectionMessageBusNodeFactory(
            ILogger_SPtr logger,
            IBus_SPtr bus,
            ISettings_SPtr settings)
         : m_logger(logger),
           m_bus(bus),
           m_settings(settings) {
        if (m_logger == nullptr) {
            throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageBusNodeFactory because 'logger' is null!", "logger");
        }

        if (m_bus == nullptr) {
            throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageBusNodeFactory because 'bus' is null!", "bus");
        }

        if (m_settings == nullptr) {
            throw ArgumentInvalidException("Can't create TemperaturesSetCorrectionMessageBusNodeFactory because 'settings' is null!", "settings");
        }
    }

    virtual ~TemperaturesSetCorrectionMessageBusNodeFactory() = default;

    virtual shared_ptr<TemperaturesSetCorrectionMessageBusNode> create(string subscriber_id) override {
        auto instance = make_shared<TemperaturesSetCorrectionMessageBusNode>(m_logger, m_bus, subscriber_id, m_settings);

        return instance;
    }

    virtual void release(shared_ptr<TemperaturesSetCorrectionMessageBusNode> bus_node) override {
    }

 private:
    ILogger_SPtr m_logger = nullptr;
    IBus_SPtr m_bus = nullptr;
    ISettings_SPtr m_settings = nullptr;
};

}
}

#endif /* SRC_FACTORIES_TEMPERATURESSETCORRECTIONMESSAGEBUSNODEFACTORY_H_ */
