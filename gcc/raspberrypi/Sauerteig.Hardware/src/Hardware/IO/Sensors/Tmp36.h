/*
 * Tmp36.h
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_IO_SENSORS_TMP36_H_
#define SRC_HARDWARE_IO_SENSORS_TMP36_H_

#include "Common/Interfaces/ILogger.h"
#include "../../Interfaces/IO/Sensors/ITmp36.h"
#include "../../Interfaces/IO/Sensors/ITmp36Logic.h"
#include "../../Interfaces/IO/AnalogeDigitalConverters/IADC.h"

using namespace Hardware::Interfaces::IO::Sensors;

namespace Hardware {
namespace IO {
namespace Sensors {
class Tmp36 : public ITmp36 {
 public:
    Tmp36(ILogger_SPtr logger, ITmp36Logic_SPtr logic);
    virtual ~Tmp36();

    void initialize(IADC_SPtr adc, adcchannel channel) override;
    bool is_value_valid() const override;
    celsius get_value() const override;
    uint get_value_raw() const override;
    void refresh() override;

 protected:
    ILogger_SPtr m_logger = nullptr;
    IADC_SPtr m_adc = nullptr;
    ITmp36Logic_SPtr m_logic;
    uint m_channel = 0;
    celsius m_value = 0;
    uint m_value_raw = 0;
    bool m_is_valid = 0;
    uint m_fail_test = 0;

 private:
    void do_refresh();
};
}
}
}

#endif /* SRC_TMP36_H_ */
