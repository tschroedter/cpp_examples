/*
 * IHeaterOffMessageHandler.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_UNITS_IHEATEROFFMESSAGEHANDLER_H_
#define SRC_INTERFACES_MONITORS_UNITS_IHEATEROFFMESSAGEHANDLER_H_

#include <memory>
#include "IOnOffMessageHandler.h"

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Units {

class IHeaterOffMessageHandler : public IOnOffMessageHandler {
 public:
    virtual ~IHeaterOffMessageHandler() = default;
};

}
}
}
}

typedef shared_ptr<Sauerteig::Interfaces::Monitors::Units::IHeaterOffMessageHandler> IHeaterOffMessageHandler_SPtr;

#endif /* SRC_INTERFACES_MONITORS_UNITS_IHEATEROFFMESSAGEHANDLER_H_ */
