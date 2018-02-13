/*
 * HeaterOffMessageBusNode.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef BUSNODES_HEATEROFFMESSAGEBUSNODE_H_
#define BUSNODES_HEATEROFFMESSAGEBUSNODE_H_

#include <memory.h>
#include <mutex>
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace BusNodes {

class HeaterOffMessageBusNode : public BusNode {
 public:
    HeaterOffMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id);
    virtual ~HeaterOffMessageBusNode() = default;

    virtual void onNotify(BaseMessage_SPtr p_base_message) override;

    virtual long get_received();

 private:
    ILogger_SPtr m_logger = nullptr;
    IBus_SPtr m_bus = nullptr;
    string m_subscriber_id = nullptr;

    mutex m_mutex{};

    long m_received = chrono::high_resolution_clock::now().time_since_epoch().count();
};

}
}

typedef shared_ptr<Sauerteig::BusNodes::HeaterOffMessageBusNode> HeaterOffMessageBusNode_SPtr;

#endif /* BUSNODES_HEATEROFFMESSAGEBUSNODE_H_ */
