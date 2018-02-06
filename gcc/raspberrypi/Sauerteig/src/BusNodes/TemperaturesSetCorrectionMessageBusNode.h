/*
 * TemperaturesSetCorrectionMessageBusNode.h
 *
 *  Created on: 30 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_BUSNODES_TEMPERATURESSETCORRECTIONMESSAGEBUSNODE_H_
#define SRC_BUSNODES_TEMPERATURESSETCORRECTIONMESSAGEBUSNODE_H_

#include <memory>
#include <string>
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"

#include "../Interfaces/ISettings.h"

using namespace std;
using namespace InMemoryBus::Common;
using namespace Sauerteig::Interfaces;

namespace Sauerteig {
namespace BusNodes {

class TemperaturesSetCorrectionMessageBusNode : public BusNode {
 public:
    TemperaturesSetCorrectionMessageBusNode(
            ILogger_SPtr logger,
            IBus_SPtr bus,
            string subscriber_id,
            ISettings_SPtr settings = nullptr);
    virtual ~TemperaturesSetCorrectionMessageBusNode() = default;

    virtual void onNotify(BaseMessage_SPtr p_base_message) override;
    virtual celsius get_inside_average_value_correction();
    virtual celsius get_outside_average_value_correction();

 private:
    ILogger_SPtr m_logger = nullptr;
    ISettings_SPtr m_settings = nullptr;

    string corrections_to_string(celsius inside, celsius outside);
};

}
}

typedef shared_ptr<Sauerteig::BusNodes::TemperaturesSetCorrectionMessageBusNode> TemperaturesSetCorrectionMessageBusNode_SPtr;

#endif /* SRC_BUSNODES_TEMPERATURESSETCORRECTIONMESSAGEBUSNODE_H_ */
