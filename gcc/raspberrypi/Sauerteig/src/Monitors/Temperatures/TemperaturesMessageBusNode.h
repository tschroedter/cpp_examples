/*
 * TemperaturesMessageBusNode.h
 *
 *  Created on: 17 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_MONITORS_TEMPERATURES_TEMPERATURESMESSAGEBUSNODE_H_
#define SRC_MONITORS_TEMPERATURES_TEMPERATURESMESSAGEBUSNODE_H_

#include <memory.h>
#include <mutex>
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "../../Messages/TemperaturesMessage.h"

using namespace std;
using namespace InMemoryBus::Common;

namespace Sauerteig {
namespace Monitors {
namespace Temperatures {

class TemperaturesMessageBusNode : public BusNode  {
 public:
    TemperaturesMessageBusNode(ILogger_SPtr logger, IBus_SPtr bus, string subscriber_id);
    virtual ~TemperaturesMessageBusNode() = default;

    virtual void onNotify(BaseMessage_SPtr p_base_message) override;

    virtual celsius get_inside_average_value();
    virtual celsius get_inside_average__percent_valid();
    virtual celsius get_outside_average_value();
    virtual celsius get_outside_average__percent_valid();

 private:
    ILogger_SPtr m_logger = nullptr;
    IBus_SPtr m_bus = nullptr;
    string m_subscriber_id = nullptr;

    mutex m_mutex{};

    celsius m_inside_average_value = 0.0;
    celsius m_inside_average__percent_valid = 0.0;
    celsius m_outside_average_value = 0.0;
    celsius m_outside_average__percent_valid = 0.0;
};

}
}
}

typedef shared_ptr<Sauerteig::Monitors::Temperatures::TemperaturesMessageBusNode> TemperaturesMessageBusNode_SPtr;

#endif /* SRC_MONITORS_TEMPERATURES_TEMPERATURESMESSAGEBUSNODE_H_ */
