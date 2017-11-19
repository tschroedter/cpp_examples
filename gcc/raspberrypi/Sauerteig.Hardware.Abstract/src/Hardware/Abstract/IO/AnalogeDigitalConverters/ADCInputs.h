/*
 * ADCTemperatures.h
 *
 *  Created on: 4 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_IO_ANALOGEDIGITALCONVERTERS__ADCTEMPERATURES_H_
#define SRC_HARDWARE_ABSTRACT_IO_ANALOGEDIGITALCONVERTERS__ADCTEMPERATURES_H_

#include "Common/CommonTypes.h"

#include "../../Interfaces/IO/AnalogeDigitalConverters/IADCInputs.h"
#include "../../Interfaces/IO/AnalogeDigitalConverters/ThreadSafe/IThreadSafeADC0832.h"

using namespace Hardware::Abstract;

namespace Hardware {
namespace Abstract {
namespace IO {
namespace AnalogeDigitalConverters {
class ADCInputs : public Interfaces::IO::AnalogeDigitalConverters::IADCInputs {
 public:
    ADCInputs(IThreadSafeADC0832_SPtr adc0832);
    virtual ~ADCInputs() = default;

    void read_value_for_channel(adcchannel channel) override;
    bool is_value_valid_for_channel(adcchannel channel) const override;
    uchar get_value_for_channel(adcchannel channel) const override;
    adcchannel get_number_of_channels() const override;

 private:
    IThreadSafeADC0832_SPtr m_adc0832;
    std::recursive_mutex m_mutex { };
};
}
}
}
}

#endif /* SRC_HARDWARE_ABSTRACT_IO_ANALOGEDIGITALCONVERTERS__ADCTEMPERATURES_H_ */
