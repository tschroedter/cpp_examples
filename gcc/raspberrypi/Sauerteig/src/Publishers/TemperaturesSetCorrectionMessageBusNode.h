/*
 * TemperaturesSetCorrectionMessageBusNode.h
 *
 *  Created on: 30 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_PUBLISHERS_TEMPERATURESSETCORRECTIONMESSAGEBUSNODE_H_
#define SRC_PUBLISHERS_TEMPERATURESSETCORRECTIONMESSAGEBUSNODE_H_

#include <memory.h>
#include <mutex>
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace Publishers {

class TemperaturesSetCorrectionMessageBusNode : public BusNode {
 public:
    TemperaturesSetCorrectionMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id);
    virtual ~TemperaturesSetCorrectionMessageBusNode() = default;

    virtual void onNotify(BaseMessage_SPtr p_base_message) override;

    virtual celsius get_inside_average_value_correction();
    virtual celsius get_outside_average_value_correction();

 private:
    ILogger_SPtr m_logger = nullptr;
    IBus_SPtr m_bus = nullptr;
    string m_subscriber_id = nullptr;

    mutex m_mutex { };

    celsius m_inside_average_value_correction = (celsius) 0;
    celsius m_outside_average_value_correction = (celsius) 0;
};

}
}

typedef shared_ptr<Sauerteig::Publishers::TemperaturesSetCorrectionMessageBusNode> TemperaturesSetCorrectionMessageBusNode_SPtr;

#endif /* SRC_PUBLISHERS_TEMPERATURESSETCORRECTIONMESSAGEBUSNODE_H_ */
