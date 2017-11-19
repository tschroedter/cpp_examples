/*
 * ISSRHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_HEATERS_ISSRHEATER_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_HEATERS_ISSRHEATER_H_

#include "../ISwitchable.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace Heaters {
class ISSRHeater : public Hardware::Abstract::Interfaces::IO::ISwitchable {
 public:
    virtual ~ISSRHeater() = default;

    virtual void initialize(ssroutputpin pin) = 0;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::Heaters::ISSRHeater> ISSRHeater_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_HEATERS_ISSRHEATER_H_ */
