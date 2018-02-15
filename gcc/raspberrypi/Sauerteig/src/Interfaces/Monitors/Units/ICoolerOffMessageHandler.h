/*
 * ICoolerOffMessageHandler.h
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_UNITS_ICOOLEROFFMESSAGEHANDLER_H_
#define SRC_INTERFACES_MONITORS_UNITS_ICOOLEROFFMESSAGEHANDLER_H_

#include <memory>
#include "IOnOffMessageHandler.h"

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Units {

class ICoolerOffMessageHandler : public IOnOffMessageHandler {
 public:
    virtual ~ICoolerOffMessageHandler() = default;
};

}
}
}
}

typedef shared_ptr<Sauerteig::Interfaces::Monitors::Units::ICoolerOffMessageHandler> ICoolerOffMessageHandler_SPtr;

#endif /* SRC_INTERFACES_MONITORS_UNITS_ICOOLEROFFMESSAGEHANDLER_H_ */
