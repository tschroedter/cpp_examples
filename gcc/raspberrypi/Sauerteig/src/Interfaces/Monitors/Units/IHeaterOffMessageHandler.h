/*
 * IHeaterOffMessageHandler.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_UNITS_IHEATEROFFMESSAGEHANDLER_H_
#define SRC_INTERFACES_MONITORS_UNITS_IHEATEROFFMESSAGEHANDLER_H_

#include <memory>
#include <chrono>

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Units {

class IHeaterOffMessageHandler {
 public:
    virtual ~IHeaterOffMessageHandler() = default;

    virtual long get_received() = 0;
};

}
}
}
}

typedef shared_ptr<Sauerteig::Interfaces::Monitors::Units::IHeaterOffMessageHandler> IHeaterOffMessageHandler_SPtr;

#endif /* SRC_INTERFACES_MONITORS_UNITS_IHEATEROFFMESSAGEHANDLER_H_ */
