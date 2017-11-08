/*
 * IADC.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADC_H_
#define HARDWARE_INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADC_H_

#include <memory>
#include "./Common/CommonTypes.h"

class IADC {
 public:
    virtual ~IADC() = default;

    virtual void read_value_for_channel(uint channel) = 0;
    virtual bool is_value_valid_for_channel(uint channel) const = 0;
    virtual uchar get_value_for_channel(uint channel) const = 0;
    virtual uint get_number_of_channels() const = 0;
};

typedef std::shared_ptr<IADC> IADC_SPtr;

#endif /* INTERFACES_IO_IADC_H_ */
