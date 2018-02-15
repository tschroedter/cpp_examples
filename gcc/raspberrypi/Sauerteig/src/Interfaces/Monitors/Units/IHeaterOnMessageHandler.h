/*
 * IHeaterOnMessageHandler.h
 *
 *  Created on: 12 Feb. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_MONITORS_IHEATERONMESSAGEHANDLER_H_
#define SRC_INTERFACES_MONITORS_IHEATERONMESSAGEHANDLER_H_

#include <memory>
#include "IOnOffMessageHandler.h"

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Monitors {
namespace Units {

class IHeaterOnMessageHandler : public IOnOffMessageHandler {
 public:
    virtual ~IHeaterOnMessageHandler() = default;
};

}
}
}
}

typedef shared_ptr<Sauerteig::Interfaces::Monitors::Units::IHeaterOnMessageHandler> IHeaterOnMessageHandler_SPtr;

#endif /* SRC_INTERFACES_MONITORS_IHEATERONMESSAGEHANDLER_H_ */
