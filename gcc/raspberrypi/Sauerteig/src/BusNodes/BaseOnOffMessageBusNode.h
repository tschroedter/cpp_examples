/*
 * BaseOnOffMessageBusNode.h
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_BUSNODES_BASEONOFFMESSAGEBUSNODE_H_
#define SRC_BUSNODES_BASEONOFFMESSAGEBUSNODE_H_

#include <memory.h>
#include <mutex>
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "InMemoryBus/Common/BaseMessage.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace BusNodes {

class BaseOnOffMessageBusNode : public BusNode {
 public:
    BaseOnOffMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id, string message_type);
    virtual ~BaseOnOffMessageBusNode() = default;

    virtual void onNotify(BaseMessage_SPtr p_base_message) override;

    virtual MessageIdType get_last_message_id();

 protected:
    ILogger_SPtr m_logger = nullptr;
    IBus_SPtr m_bus = nullptr;
    string m_subscriber_id = nullptr;

    mutex m_mutex{};

    MessageIdType m_last_message_id = 0;
};

}
}

typedef shared_ptr<Sauerteig::BusNodes::BaseOnOffMessageBusNode> BaseOnOffMessageBusNode_SPtr;

#endif /* SRC_BUSNODES_BASEONOFFMESSAGEBUSNODE_H_ */
