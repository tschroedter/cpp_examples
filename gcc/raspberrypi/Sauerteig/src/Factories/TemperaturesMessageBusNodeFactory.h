/*
 * TemperaturesMessageBusNodeFactory.h
 *
 *  Created on: 17 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_FACTORIES_TEMPERATURESMESSAGEBUSNODEFACTORY_H_
#define SRC_FACTORIES_TEMPERATURESMESSAGEBUSNODEFACTORY_H_

#include <string.h>
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "../Interfaces/Factories/ITemperaturesMessageBusNodeFactory.h"
#include "../Monitors/Temperatures/TemperaturesMessageBusNode.h"

using namespace Sauerteig::Interfaces::Factories;

namespace Sauerteig {
namespace Factories {

class TemperaturesMessageBusNodeFactory : public ITemperaturesMessageBusNodeFactory {
 public:
    TemperaturesMessageBusNodeFactory(ILogger_SPtr logger, IBus_SPtr bus);
    virtual ~TemperaturesMessageBusNodeFactory() = default;

    TemperaturesMessageBusNode_SPtr create(std::string subscriber_id) override;
    void release(TemperaturesMessageBusNode_SPtr bus_node) override;

 private:
    ILogger_SPtr m_logger = nullptr;
    IBus_SPtr m_bus = nullptr;
};

}
}

#endif /* SRC_FACTORIES_TEMPERATURESMESSAGEBUSNODEFACTORY_H_ */
