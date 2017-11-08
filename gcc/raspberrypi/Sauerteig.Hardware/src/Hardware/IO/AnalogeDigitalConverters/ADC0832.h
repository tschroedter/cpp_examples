/*
 * ADC0832.h
 *
 *  Created on: 31 Oct. 2017
 *      Author: tom
 */

#ifndef HARDWARE_IO_ANALOGEDIGITALCONVERTERS_ADC0832_H_
#define HARDWARE_IO_ANALOGEDIGITALCONVERTERS_ADC0832_H_

#include <vector>
#include "../../Interfaces/IO/AnalogeDigitalConverters/IADC0832.h"

#define DEFAULT_ADC_PIN_CS  0
#define DEFAULT_ADC_PIN_DIO 1
#define DEFAULT_ADC_CLK     2

class ADC0832 : public IADC0832 {
 public:
    ADC0832();
    ADC0832(uint number_of_channels, uint pin_cs, uint pin_dio, uint pin_clk);
    virtual ~ADC0832();

    void read_value_for_channel(uint channel) override;
    bool is_value_valid_for_channel(uint channel) const override;
    uchar get_value_for_channel(uint channel) const override;
    uint get_number_of_channels() const override;
    uint get_pin_cs() const override;
    uint get_pin_dio() const override;
    uint get_pin_clk() const override;
    void initialize(uint number_of_channels, uint pin_cs, uint pin_dio,
                    uint pin_clk) override;

 private:
    uint m_number_of_channels = 2;
    uint m_pin_cs = DEFAULT_ADC_PIN_CS;
    uint m_pin_dio = DEFAULT_ADC_PIN_DIO;
    uint m_pin_clk = DEFAULT_ADC_CLK;

    std::vector<uchar> m_data;
    std::vector<bool> m_is_data_valid;

    uchar read_value_for_channel_1();
    uchar read_value_for_channel_2();
    void after_read_value();
    void before_for_read_value(uint channel);
    void initialize_with_default_values();
};

#endif /* ADC0832_H_ */
