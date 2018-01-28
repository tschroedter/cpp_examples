/*
 * IOutputManager.h
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_INTERFACES_IO_SERIALSHIFTREGISTER_ISSROUTPUTS_H_
#define HARDWARE_ABSTRACT_INTERFACES_IO_SERIALSHIFTREGISTER_ISSROUTPUTS_H_

#include <memory>
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace SerialShiftRegister {
class ISSROutputs {
 public:
    virtual ~ISSROutputs() = default;

    virtual void high(ssroutputpin pin) = 0;
    virtual void low(ssroutputpin pin) = 0;
    virtual bool is_high(ssroutputpin pin) const = 0;
};
}
}
}
}
}

typedef std::shared_ptr<Hardware::Abstract::Interfaces::IO::SerialShiftRegister::ISSROutputs> ISSROutputs_SPtr;

#endif /* HARDWARE_ABSTRACT_INTERFACES_IO_SERIALSHIFTREGISTER_ISSROUTPUTS_H_ */
