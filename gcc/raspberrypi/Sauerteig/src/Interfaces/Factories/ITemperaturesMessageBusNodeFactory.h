/*
 * ITemperaturesMessageBusNodeFactory.h
 *
 *  Created on: 17 Jan. 2018
 *      Author: tom
 */

#ifndef INTERFACES_FACTORIES_ITEMPERATURESMESSAGEBUSNODEFACTORY_H_
#define INTERFACES_FACTORIES_ITEMPERATURESMESSAGEBUSNODEFACTORY_H_

#include <memory>
#include "../../Monitors/Temperatures/TemperaturesMessageBusNode.h"

namespace Sauerteig {
namespace Interfaces {
namespace Factories {

class ITemperaturesMessageBusNodeFactory {
 public:
    virtual ~ITemperaturesMessageBusNodeFactory() = default;

    virtual TemperaturesMessageBusNode_SPtr create(std::string subscriber_id) = 0;
    virtual void release(TemperaturesMessageBusNode_SPtr bus_node) = 0;
};

}
}
}

typedef std::shared_ptr<Sauerteig::Interfaces::Factories::ITemperaturesMessageBusNodeFactory> ITemperaturesMessageBusNodeFactory_SPtr;

#endif /* INTERFACES_FACTORIES_ITEMPERATURESMESSAGEBUSNODEFACTORY_H_ */
