/*
 * IADC0832.h
 *
 *  Created on: 31 Oct. 2017
 *      Author: tom
 */

#ifndef INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADC0832_H_
#define INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADC0832_H_

#include <memory>
#include "IADC.h"
#include "../../../CommonTypes.h"

class IADC0832 : public IADC {
 public:
    virtual ~IADC0832() = default;

    virtual uint get_pin_cs() const = 0;
    virtual uint get_pin_dio() const = 0;
    virtual uint get_pin_clk() const = 0;
    virtual void initialize(uint number_of_channels, uint pin_cs, uint pin_dio,
                            uint pin_clk) = 0;
};

typedef std::shared_ptr<IADC0832> IADC0832_SPtr;

#endif /* IADC0832_H_ */
