/*
 * ICoolerOnMessageHandler.h
 *
 *  Created on: 15 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_UNITS_ICOOLERONMESSAGEHANDLER_H_
#define SRC_INTERFACES_MONITORS_UNITS_ICOOLERONMESSAGEHANDLER_H_

#include <memory>
#include "IOnOffMessageHandler.h"

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Units {

class ICoolerOnMessageHandler : public IOnOffMessageHandler {
 public:
    virtual ~ICoolerOnMessageHandler() = default;
};

}
}
}
}

typedef shared_ptr<Sauerteig::Interfaces::Monitors::Units::ICoolerOnMessageHandler> ICoolerOnMessageHandler_SPtr;

#endif /* SRC_INTERFACES_MONITORS_UNITS_ICOOLERONMESSAGEHANDLER_H_ */
