/*
 * Tmp36.h
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#ifndef IO_SENSORS_TMP36_H_
#define IO_SENSORS_TMP36_H_

#include "../../Interfaces/IO/Sensors/ITmp36.h"
#include "../../Interfaces/IO/AnalogeDigitalConverters/IADCTemperatures.h"

class Tmp36 : public ITmp36 {
 public:
    Tmp36(IADCTemperatures_SPtr adc);
    virtual ~Tmp36();

    void initialize(uint channel) override;
    bool is_value_valid() const override;
    uint get_value() const override;
    uint get_value_raw() const override;
    void refresh() override;

 private:
    IADCTemperatures_SPtr m_adc = nullptr;
    uint m_channel = 0;
    uint m_value = 0;
    uint m_value_raw = 0;
    bool m_is_valid = 0;
};

#endif /* TMP36_H_ */
