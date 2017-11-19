/*
 * IPulseGeneratoreServer.h
 *
 *  Created on: 10 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_INTERFACES_IO_IPULSEGENERATORESERVER_H_
#define SRC_HARDWARE_ABSTRACT_INTERFACES_IO_IPULSEGENERATORESERVER_H_

#include <memory>
#include "ISwitchable.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
class IPulseGeneratoreServer {
 public:
    virtual ~IPulseGeneratoreServer() = default;

    virtual void operator()() = 0;

    virtual void initialize(ISwitchable_SPtr switchable) = 0;
    virtual void on() = 0;
    virtual void off() = 0;
    virtual bool is_on() const = 0;

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void set_on_interval_in_msec(uint interval) = 0;
    virtual void set_off_interval_in_msec(uint interval) = 0;
    virtual uint get_on_interval_in_msec() = 0;
    virtual uint get_off_interval_in_msec() = 0;
    virtual void do_one_flash() = 0;
    virtual bool is_flashing_enable() const = 0;
};
}
}
}
}

typedef std::shared_ptr<
        Hardware::Abstract::Interfaces::IO::IPulseGeneratoreServer> IPulseGeneratoreServer_SPtr;

#endif /* SRC_HARDWARE_ABSTRACT_INTERFACES_IO_IPULSEGENERATORESERVER_H_ */
