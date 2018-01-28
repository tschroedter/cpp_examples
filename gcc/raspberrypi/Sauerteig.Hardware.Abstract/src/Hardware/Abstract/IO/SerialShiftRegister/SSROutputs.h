/*
 * OutputManager.h
 *
 *  Created on: 13 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_SSROUTPUTS_H_
#define HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_SSROUTPUTS_H_

#include "Common/CommonTypes.h"
#include "../../Interfaces/IO/SerialShiftRegister/ThreadSafe/IThreadSafeSerialShiftRegisterManager.h"
#include "../../Interfaces/IO/SerialShiftRegister/ISSROutputs.h"

namespace Hardware {
namespace Abstract {
namespace IO {
namespace SerialShiftRegister {
class SSROutputs : public Hardware::Abstract::Interfaces::IO::SerialShiftRegister::ISSROutputs {
 public:
    SSROutputs(IThreadSafeSerialShiftRegisterManager_SPtr manager);
    virtual ~SSROutputs() = default;

    void high(ssroutputpin pin) override;
    void low(ssroutputpin pin) override;
    bool is_high(ssroutputpin pin) const override;

 private:
    IThreadSafeSerialShiftRegisterManager_SPtr m_manager;
};
}
}
}
}

#endif /* HARDWARE_ABSTRACT_IO_SERIALSHIFTREGISTER_SSROUTPUTS_H_ */
