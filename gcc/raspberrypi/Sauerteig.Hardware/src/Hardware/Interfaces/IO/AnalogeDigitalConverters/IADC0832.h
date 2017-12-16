/*
 * IADC0832.h
 *
 *  Created on: 31 Oct. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADC0832_H_
#define SRC_HARDWARE_INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADC0832_H_

#include <memory>
#include "IADC.h"
#include "Common/CommonTypes.h"

namespace Hardware {
namespace Interfaces {
namespace IO {
namespace AnalogeDigitalConverters {
class IADC0832 : public IADC {
 public:
    virtual ~IADC0832() = default;

    virtual uint get_pin_cs() const = 0;
    virtual uint get_pin_dio() const = 0;
    virtual uint get_pin_clk() const = 0;
    virtual void initialize(adcchannel number_of_channels, wiringpipin pin_cs, wiringpipin pin_dio,
                            wiringpipin pin_clk) = 0;
};
}
}
}
}

typedef std::shared_ptr<Hardware::Interfaces::IO::AnalogeDigitalConverters::IADC0832> IADC0832_SPtr;

#endif /* SRC_HARDWARE_INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADC0832_H_ */
