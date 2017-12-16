/*
 * ISSRHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_UNITS_INTERFACES_IO_COOLERS_ISSRCOOLER_H_
#define HARDWARE_UNITS_INTERFACES_IO_COOLERS_ISSRCOOLER_H_

#include <memory>
#include "Hardware/Abstract/Interfaces/IO/ISwitchable.h"

namespace Hardware {
namespace Units {
namespace Interfaces {
namespace IO {
namespace Coolers {
class ISSRCooler : public Hardware::Abstract::Interfaces::IO::ISwitchable {
 public:
    virtual ~ISSRCooler() = default;

    virtual void initialize(ssroutputpin pin) = 0;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Units::Interfaces::IO::Coolers::ISSRCooler> ISSRCooler_SPtr;

#endif /* HARDWARE_UNITS_INTERFACES_IO_COOLERS_ISSRCOOLER_H_ */
