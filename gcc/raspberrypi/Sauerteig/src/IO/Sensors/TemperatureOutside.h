/*
 * TemperatureOutside.h
 *
 *  Created on: 6 Nov. 2017
 *      Author: tom
 */

#ifndef IO_SENSORS_TEMPERATUREOUTSIDE_H_
#define IO_SENSORS_TEMPERATUREOUTSIDE_H_

#include "../../Interfaces/IO/Sensors/ITemperatureOutside.h"
#include "./Hardware/Interfaces/IO/Sensors/ITmp36.h"

class TemperatureOutside : public ITemperatureOutside {
 public:
    TemperatureOutside(ITmp36_SPtr tmp36);
    virtual ~TemperatureOutside() = default;

    void initialize(uint channel) override;
    bool is_value_valid() const override;
    uint get_value() const override;
    uint get_value_raw() const override;
    void refresh() override;

 private:
    ITmp36_SPtr m_tmp36;
};

#endif /* IO_SENSORS_TEMPERATUREOUTSIDE_H_ */
