/*
 * CoolerOffMessageBusNode.h
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_BUSNODES_COOLEROFFMESSAGEBUSNODE_H_
#define SRC_BUSNODES_COOLEROFFMESSAGEBUSNODE_H_

#include <memory.h>
#include "BaseOnOffMessageBusNode.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"

using namespace std;

namespace Sauerteig {
namespace BusNodes {

class CoolerOffMessageBusNode : public BaseOnOffMessageBusNode {
 public:
    CoolerOffMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id);
    virtual ~CoolerOffMessageBusNode() = default;
};

}
}

typedef shared_ptr<Sauerteig::BusNodes::CoolerOffMessageBusNode> CoolerOffMessageBusNode_SPtr;


#endif /* SRC_BUSNODES_COOLEROFFMESSAGEBUSNODE_H_ */
