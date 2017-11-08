/*
 * I74HC595.h
 *
 *  Created on: 7 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_INTERFACES_IO_SERIALSHIFTREGISTER_I74HC595_H_
#define HARDWARE_INTERFACES_IO_SERIALSHIFTREGISTER_I74HC595_H_

#include <memory>
#include "Common/CommonTypes.h"

class I74HC595 {
 public:
    virtual ~I74HC595() = default;

    virtual uint get_pin_ds() const = 0;
    virtual uint get_pin_st_cp() const = 0;
    virtual uint get_pin_sh_cp() const = 0;
    virtual void initialize(uint pin_ds, uint pin_sh_dp, uint pin_sh_cp) = 0;
};

typedef std::shared_ptr<I74HC595> I74HC595_SPtr;

#endif /* SRC_HARDWARE_INTERFACES_IO_SERIALSHIFTREGISTER_I74HC595_H_ */
