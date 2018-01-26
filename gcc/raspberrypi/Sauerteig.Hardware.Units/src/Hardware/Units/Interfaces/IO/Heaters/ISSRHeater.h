/*
 * ISSRHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_ISSRHEATER_H_
#define SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_ISSRHEATER_H_

#include <memory>
#include "Hardware/Abstract/Interfaces/IO/ISwitchable.h"

using namespace Hardware::Abstract::Interfaces::IO;

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Heaters {
class ISSRHeater : public ISwitchable {
 public:
    virtual ~ISSRHeater() = default;

    virtual void initialize(ssroutputpin pin) = 0;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Heaters::ISSRHeater> ISSRHeater_SPtr;

#endif /* SRC_HARDWARE_UNITS_INTERFACES_IO_HEATERS_ISSRHEATER_H_ */
