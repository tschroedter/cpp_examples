/*
 * ADC0832.h
 *
 *  Created on: 31 Oct. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_IO_ANALOGEDIGITALCONVERTERS_ADC0832_H_
#define SRC_HARDWARE_IO_ANALOGEDIGITALCONVERTERS_ADC0832_H_

#include <vector>
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/IO/AnalogeDigitalConverters/IADC0832.h"

#define DEFAULT_ADC_PIN_CS  0
#define DEFAULT_ADC_PIN_DIO 1
#define DEFAULT_ADC_CLK     2

using namespace Hardware::Interfaces::IO::AnalogeDigitalConverters;

namespace Hardware {
namespace IO {
namespace AnalogeDigitalConverters {
class ADC0832 : public IADC0832 {
 public:
    ADC0832(ILogger_SPtr logger);
    ADC0832(adcchannel number_of_channels, wiringpipin pin_cs, wiringpipin pin_dio, wiringpipin pin_clk);
    virtual ~ADC0832();

    void read_value_for_channel(adcchannel channel) override;
    bool is_value_valid_for_channel(adcchannel channel) const override;
    uchar get_value_for_channel(adcchannel channel) const override;
    adcchannel get_number_of_channels() const override;
    wiringpipin get_pin_cs() const override;
    wiringpipin get_pin_dio() const override;
    wiringpipin get_pin_clk() const override;
    void initialize(adcchannel number_of_channels, wiringpipin pin_cs, wiringpipin pin_dio, wiringpipin pin_clk)
            override;

 private:
    ILogger_SPtr m_logger = nullptr;
    adcchannel m_number_of_channels = 2;
    wiringpipin m_pin_cs = DEFAULT_ADC_PIN_CS;
    wiringpipin m_pin_dio = DEFAULT_ADC_PIN_DIO;
    wiringpipin m_pin_clk = DEFAULT_ADC_CLK;

    std::vector<uchar> m_data;
    std::vector<bool> m_is_data_valid;

    uchar read_value_for_channel_1();
    uchar read_value_for_channel_2();
    void after_read_value();
    void before_for_read_value(adcchannel channel);
    void initialize_with_default_values();
    void validate_channel(adcchannel channel) const;
};
}
}
}

#endif /* SRC_HARDWARE_IO_ANALOGEDIGITALCONVERTERS_ADC0832_H_ */
