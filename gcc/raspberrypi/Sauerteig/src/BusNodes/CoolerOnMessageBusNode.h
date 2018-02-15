/*
 * CoolerOnMessageBusNode.h
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_BUSNODES_COOLERONMESSAGEBUSNODE_H_
#define SRC_BUSNODES_COOLERONMESSAGEBUSNODE_H_

#include <memory.h>
#include "BaseOnOffMessageBusNode.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"

using namespace std;

namespace Sauerteig {
namespace BusNodes {

class CoolerOnMessageBusNode : public BaseOnOffMessageBusNode {
 public:
    CoolerOnMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id);
    virtual ~CoolerOnMessageBusNode() = default;
};

}
}

typedef shared_ptr<Sauerteig::BusNodes::CoolerOnMessageBusNode> CoolerOnMessageBusNode_SPtr;

#endif /* SRC_BUSNODES_COOLERONMESSAGEBUSNODE_H_ */
