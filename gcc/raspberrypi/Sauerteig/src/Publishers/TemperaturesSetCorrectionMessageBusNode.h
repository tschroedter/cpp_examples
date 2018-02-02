/*
 * TemperaturesSetCorrectionMessageBusNode.h
 *
 *  Created on: 30 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_PUBLISHERS_TEMPERATURESSETCORRECTIONMESSAGEBUSNODE_H_
#define SRC_PUBLISHERS_TEMPERATURESSETCORRECTIONMESSAGEBUSNODE_H_

#include <memory.h>
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "../Interfaces/Publishers/ITemperaturesPublisherSettings.h"

using namespace std;
using namespace InMemoryBus::Common;
using namespace Sauerteig::Interfaces::Publishers;

namespace Sauerteig {
namespace Publishers {

class TemperaturesSetCorrectionMessageBusNode : public BusNode {
 public:
    TemperaturesSetCorrectionMessageBusNode(
            ILogger_SPtr logger,
            IBus_SPtr bus,
            string subscriber_id,
            ITemperaturesPublisherSettings_SPtr settings = nullptr);
    virtual ~TemperaturesSetCorrectionMessageBusNode() = default;

    virtual void onNotify(BaseMessage_SPtr p_base_message) override;

 private:
    ILogger_SPtr m_logger = nullptr;
    ITemperaturesPublisherSettings_SPtr m_settings = nullptr;
};

}
}

typedef shared_ptr<Sauerteig::Publishers::TemperaturesSetCorrectionMessageBusNode> TemperaturesSetCorrectionMessageBusNode_SPtr;

#endif /* SRC_PUBLISHERS_TEMPERATURESSETCORRECTIONMESSAGEBUSNODE_H_ */
