/*
 * IFlashable.h
 *
 *  Created on: 16 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_IFLASHABLE_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_IFLASHABLE_H_

#include "Common/CommonTypes.h"
#include "ISwitchable.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
class IFlashable : public ISwitchable {
 public:
    virtual ~IFlashable() = default;

    virtual uint get_off_interval_in_msec() = 0;
    virtual uint get_on_interval_in_msec() = 0;
    virtual bool is_flashing_enable() const = 0;
    virtual void set_off_interval_in_msec(uint interval) = 0;
    virtual void set_on_interval_in_msec(uint interval) = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
};
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::IFlashable> IFlashable_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_IFLASHABLE_H_ */
