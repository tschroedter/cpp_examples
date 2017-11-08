/*
 * ADCTemperatures.h
 *
 *  Created on: 4 Nov. 2017
 *      Author: tom
 */

#ifndef IO_ANALOGEDIGITALCONVERTERS__ADCTEMPERATURES_H_
#define IO_ANALOGEDIGITALCONVERTERS__ADCTEMPERATURES_H_

#include "./Hardware/Interfaces/IO/AnalogeDigitalConverters/IADCTemperatures.h"
#include "./Hardware/Interfaces/IO/AnalogeDigitalConverters/ThreadSafe/IThreadSafeADC0832.h"

class ADCTemperatures : public IADCTemperatures {
 public:
    ADCTemperatures(IThreadSafeADC0832_SPtr adc0832);
    virtual ~ADCTemperatures() = default;

    void read_value_for_channel(uint channel) override;
    bool is_value_valid_for_channel(uint channel) const override;
    uchar get_value_for_channel(uint channel) const override;
    uint get_number_of_channels() const override;
    void initialize(uint number_of_channels, uint pin_cs, uint pin_dio,
                    uint pin_clk);

 private:
    IThreadSafeADC0832_SPtr m_adc0832;
    std::recursive_mutex m_mutex { };
};

#endif /* IO_ADCTEMPERATURES_H_ */
