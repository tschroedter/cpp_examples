/*
 * HeaterOffMessageBusNode.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_BUSNODES_HEATEROFFMESSAGEBUSNODE_H_
#define SRC_BUSNODES_HEATEROFFMESSAGEBUSNODE_H_

#include <memory.h>
#include <mutex>
#include "BaseOnOffMessageBusNode.h"
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "InMemoryBus/Common/BaseMessage.h"

using namespace std;

namespace Sauerteig {
namespace BusNodes {

class HeaterOffMessageBusNode : public BaseOnOffMessageBusNode {
 public:
    HeaterOffMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id);
    virtual ~HeaterOffMessageBusNode() = default;
};

}
}

typedef shared_ptr<Sauerteig::BusNodes::HeaterOffMessageBusNode> HeaterOffMessageBusNode_SPtr;

#endif /* SRC_BUSNODES_HEATEROFFMESSAGEBUSNODE_H_ */
