/*
 * ITemperaturesSetCorrectionMessageBusNodeFactory.h
 *
 *  Created on: 2 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_FACTORIES_ITEMPERATURESSETCORRECTIONMESSAGEBUSNODEFACTORY_H_
#define SRC_INTERFACES_FACTORIES_ITEMPERATURESSETCORRECTIONMESSAGEBUSNODEFACTORY_H_

#include <memory>
#include "IMessageBusNodeFactory.h"
#include "../../BusNodes/TemperaturesSetCorrectionMessageBusNode.h"

using namespace std;
using namespace Sauerteig::BusNodes;

namespace Sauerteig {
namespace Interfaces {
namespace Factories {

class ITemperaturesSetCorrectionMessageBusNodeFactory
: public IMessageBusNodeFactory<TemperaturesSetCorrectionMessageBusNode>{
 public:
    virtual ~ITemperaturesSetCorrectionMessageBusNodeFactory() = default;
};

}
}
}

typedef std::shared_ptr<Sauerteig::Interfaces::Factories::ITemperaturesSetCorrectionMessageBusNodeFactory> ITemperaturesSetCorrectionMessageBusNodeFactory_SPtr;

#endif /* SRC_INTERFACES_FACTORIES_ITEMPERATURESSETCORRECTIONMESSAGEBUSNODEFACTORY_H_ */
