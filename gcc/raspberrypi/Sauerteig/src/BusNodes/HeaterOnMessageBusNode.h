/*
 * HeaderOnMessageBusNode.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_BUSNODES_HEATERONMESSAGEBUSNODE_H_
#define SRC_BUSNODES_HEATERONMESSAGEBUSNODE_H_

#include <memory.h>
#include <mutex>
#include "BaseOnOffMessageBusNode.h"
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "InMemoryBus/Common/BaseMessage.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace BusNodes {

class HeaterOnMessageBusNode : public BaseOnOffMessageBusNode {
 public:
    HeaterOnMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id);
    virtual ~HeaterOnMessageBusNode() = default;
};

}
}

typedef shared_ptr<Sauerteig::BusNodes::HeaterOnMessageBusNode> HeaterOnMessageBusNode_SPtr;

#endif /* SRC_BUSNODES_HEATERONMESSAGEBUSNODE_H_ */
