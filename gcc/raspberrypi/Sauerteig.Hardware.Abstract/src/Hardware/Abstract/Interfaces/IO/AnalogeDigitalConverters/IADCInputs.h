/*
 * IADCTemperatures.h
 *
 *  Created on: 4 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ANALOGEDIGITALCONVERTERS__IADCTEMPERATURES_H_
#define SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ANALOGEDIGITALCONVERTERS__IADCTEMPERATURES_H_

#include <memory>
#include "Common/CommonTypes.h"
#include "Hardware/Interfaces/IO/AnalogeDigitalConverters/IADC.h"

using namespace Hardware::Interfaces::IO::AnalogeDigitalConverters;

namespace Hardware {
namespace Abstract {
namespace Interfaces {
namespace IO {
namespace AnalogeDigitalConverters {
class IADCInputs : public IADC {
 public:
    virtual ~IADCInputs() = default;
};
}
}
}
}
}

typedef std::shared_ptr<
        Hardware::Abstract::Interfaces::IO::AnalogeDigitalConverters::IADCInputs> IADCInputs_SPtr;

#endif /* SRC_HARDWARE_ABSTRACT_INTERFACES_IO_ANALOGEDIGITALCONVERTERS__IADCTEMPERATURES_H_ */
