/*
 * SSR74HC595.h
 *
 *  Created on: 7 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_IO_SERIALSHIFTREGISTER_SSR74HC595_H_
#define SRC_HARDWARE_IO_SERIALSHIFTREGISTER_SSR74HC595_H_

#include "Common/CommonTypes.h"
#include "../../Interfaces/IO/SerialShiftRegister/I74HC595.h"

// todo finish this class
class SSR74HC595 : public I74HC595 {
 public:
    SSR74HC595();
    virtual ~SSR74HC595() = default;

    uint get_pin_ds() const override;
    uint get_pin_st_cp() const override;
    uint get_pin_sh_cp() const override;
    void initialize(uint pin_ds, uint pin_sh_dp, uint pin_sh_cp) override;

 private:
    uint m_pin_ds;
    uint m_pin_st_cp;
    uint m_pin_sh_cp;
};

#endif /* SRC_HARDWARE_IO_SERIALSHIFTREGISTER_SSR74HC595_H_ */
