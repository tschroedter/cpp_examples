/*
 * ILEDFlashingServer.h
 *
 *  Created on: 10 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ISWITCHABLEFLASHINGSERVER_H_
#define SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ISWITCHABLEFLASHINGSERVER_H_

#include "Common/CommonTypes.h"
#include "IFlashable.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
class ISwitchableFlashingServer : public IFlashable {
 public:
    virtual ~ISwitchableFlashingServer() = default;

    virtual void initialize(ISwitchable_SPtr switchable) = 0;
};
}
}
}
}

typedef std::shared_ptr<
        Hardware::Abstract::Interfaces::IO::ISwitchableFlashingServer> ISwitchableFlashingServer_SPtr;

#endif /* SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ISWITCHABLEFLASHINGSERVER_H_ */
