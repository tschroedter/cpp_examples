/*
 * ThreadSafeADC0832.h
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_IO_ANALOGEDIGITALCONVERTERS_THREADSAFE_THREADSAFEADC0832_H_
#define SRC_HARDWARE_ABSTRACT_IO_ANALOGEDIGITALCONVERTERS_THREADSAFE_THREADSAFEADC0832_H_

#include <mutex>
#include "Hardware/Interfaces/IO/AnalogeDigitalConverters/IADC0832.h"
#include "../../../Interfaces/IO/AnalogeDigitalConverters/ThreadSafe/IThreadSafeADC0832.h"

using namespace Hardware::Abstract;

namespace Hardware {
namespace Abstract {
namespace IO {
namespace AnalogeDigitalConverters {
namespace ThreadSafe {
class ThreadSafeADC0832 : public Interfaces::IO::AnalogeDigitalConverters::ThreadSafe::IThreadSafeADC0832 {
 public:
    ThreadSafeADC0832(IADC0832_SPtr adc0832);
    virtual ~ThreadSafeADC0832() = default;

    void read_value_for_channel(adcchannel channel) override;
    bool is_value_valid_for_channel(adcchannel channel) const override;
    uchar get_value_for_channel(adcchannel channel) const override;
    adcchannel get_number_of_channels() const override;
    uint get_pin_cs() const override;
    uint get_pin_dio() const override;
    uint get_pin_clk() const override;
    void initialize(adcchannel number_of_channels, wiringpipin pin_cs, wiringpipin pin_dio, wiringpipin pin_clk)
            override;
    void set_adc0832(IADC0832_SPtr adc0832) override;

 private:
    IADC0832_SPtr m_adc0832;
    std::recursive_mutex m_mutex { };
};
}
}
}
}
}
// TODO AnalogeDigitalConvertes
//      AnalogeDigitalConverters
typedef std::shared_ptr<Hardware::Abstract::IO::AnalogeDigitalConverters::ThreadSafe::ThreadSafeADC0832> ThreadSafeADC0832_SPtr;

#endif /* SRC_HARDWARE_ABSTRACT_IO_ANALOGEDIGITALCONVERTERS_THREADSAFE_THREADSAFEADC0832_H_ */
