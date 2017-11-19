/*
 * IADC.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADC_H_
#define SRC_HARDWARE_INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADC_H_

#include <memory>
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Interfaces {
namespace IO {
namespace AnalogeDigitalConverters {
class IADC {
 public:
    virtual ~IADC() = default;

    virtual void read_value_for_channel(adcchannel channel) = 0;
    virtual bool is_value_valid_for_channel(adcchannel channel) const = 0;
    virtual uchar get_value_for_channel(adcchannel channel) const = 0;
    virtual adcchannel get_number_of_channels() const = 0;
};
}
}
}
}

typedef std::shared_ptr<Hardware::Interfaces::IO::AnalogeDigitalConverters::IADC> IADC_SPtr;

#endif /* SRC_HARDWARE_INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADC_H_ */
