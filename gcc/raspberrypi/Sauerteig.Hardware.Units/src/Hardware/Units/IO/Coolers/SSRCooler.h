/*
 * SSRHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_UNITS_IO_COOLERS_SSRHEATER_H_
#define SRC_HARDWARE_UNITS_IO_COOLERS_SSRHEATER_H_

#include "Common/CommonTypes.h"
#include "../../Interfaces/IO/Coolers/ISSRCooler.h"
#include "Hardware/Abstract/Interfaces/IO/SerialShiftRegister/ISSROutputs.h"

namespace Hardware {
namespace Units {
namespace IO {
namespace Coolers {
class SSRCooler : public Hardware::Units::Interfaces::IO::Coolers::ISSRCooler {
 public:
    SSRCooler(ISSROutputs_SPtr ssr);
    virtual ~SSRCooler() = default;

    void initialize(ssroutputpin pin) override;

    void on() override;
    void off() override;
    bool is_on() const override;

 private:
    ISSROutputs_SPtr m_ssr = nullptr;
    ssroutputpin m_pin = 0;
};
}
}
}
}

#endif /* SRC_HARDWARE_UNITS_IO_COOLERS_SSRHEATER_H_ */
