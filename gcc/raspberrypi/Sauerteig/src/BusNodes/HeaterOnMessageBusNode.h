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
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace BusNodes {

class HeaterOnMessageBusNode : public BusNode {
 public:
    HeaterOnMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id);
    virtual ~HeaterOnMessageBusNode() = default;

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

typedef shared_ptr<Sauerteig::BusNodes::HeaterOnMessageBusNode> HeaterOnMessageBusNode_SPtr;

#endif /* SRC_BUSNODES_HEATERONMESSAGEBUSNODE_H_ */
