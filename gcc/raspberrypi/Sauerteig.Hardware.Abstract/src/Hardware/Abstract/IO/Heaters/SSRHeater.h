/*
 * SSRHeater.h
 *
 *  Created on: 17 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_IO_HEATERS_SSRHEATER_H_
#define HARDWARE_ABSTRACT_IO_HEATERS_SSRHEATER_H_

#include "Common/CommonTypes.h"
#include "../../Interfaces/IO/Heaters/ISSRHeater.h"
#include "../../Interfaces/IO/SerialShiftRegister/ISSROutputs.h"

namespace Hardware {
namespace Abstract {
namespace IO {
namespace Heaters {
class SSRHeater : public Hardware::Abstract::Interfaces::IO::Heaters::ISSRHeater {
 public:
    SSRHeater(ISSROutputs_SPtr ssr);
    virtual ~SSRHeater() = default;

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

#endif /* HARDWARE_ABSTRACT_IO_HEATERS_SSRHEATER_H_ */
