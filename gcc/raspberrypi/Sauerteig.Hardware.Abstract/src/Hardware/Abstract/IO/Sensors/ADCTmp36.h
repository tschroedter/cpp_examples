/*
 * ADCTmp36.h
 *
 *  Created on: 14 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_IO_SENSORS_ADCTMP36_H_
#define HARDWARE_ABSTRACT_IO_SENSORS_ADCTMP36_H_

#include "Hypodermic/FactoryWrapper.h"
#include "../../Interfaces/IO/Sensors/IADCTmp36.h"
#include "../../Interfaces/IO/AnalogeDigitalConverters/IADCInputs.h"
#include "Hardware/Interfaces/IO/Sensors/ITmp36.h"

namespace Hardware {
namespace Abstract {
namespace IO {
namespace Sensors {
class ADCTmp36 : public Hardware::Abstract::Interfaces::IO::Sensors::IADCTmp36 {
 public:
    ADCTmp36(IADCInputs_SPtr adc, ITmp36_SPtr tmp36);
    virtual ~ADCTmp36() = default;

    void initialize(adcchannel channel) override;
    bool is_value_valid() const override;
    celsius get_value() const override;
    void refresh() override;

 private:
    IADCInputs_SPtr m_adc;
    ITmp36_SPtr m_tmp36;
    std::function<ITmp36_SPtr()> m_factory;
};
}
}
}
}

#endif /* HARDWARE_ABSTRACT_IO_SENSORS_ADCTMP36_H_ */
