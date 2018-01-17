/*
 * ITemperaturesMessageHandler.h
 *
 *  Created on: 16 Jan. 2018
 *      Author: tom
 */

#ifndef INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMESSAGEHANDLER_H_
#define INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMESSAGEHANDLER_H_

#include <memory>

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Temperatures {

class ITemperaturesMessageHandler {
 public:
    virtual ~ITemperaturesMessageHandler() = default;

    virtual void operator()() = 0;
};

}
}
}
}

typedef std::shared_ptr<Sauerteig::Interfaces::Monitors::Temperatures::ITemperaturesMessageHandler> ITemperaturesMessageHandler_SPtr;

#endif /* INTERFACES_MONITORS_TEMPERATURES_ITEMPERATURESMESSAGEHANDLER_H_ */
