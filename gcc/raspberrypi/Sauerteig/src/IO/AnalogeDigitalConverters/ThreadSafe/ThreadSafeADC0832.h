/*
 * ThreadSafeADC0832.h
 *
 *  Created on: 3 Nov. 2017
 *      Author: tom
 */

#ifndef IO_ANALOGEDIGITALCONVERTERS_THREADSAFE_THREADSAFEADC0832_H_
#define IO_ANALOGEDIGITALCONVERTERS_THREADSAFE_THREADSAFEADC0832_H_

#include <mutex>
#include "../../../Interfaces/IO/AnalogeDigitalConverters/IADC0832.h"
#include "../../../Interfaces/IO/AnalogeDigitalConverters/ThreadSafe/IThreadSafeADC0832.h"

class ThreadSafeADC0832 : public IThreadSafeADC0832 {
 public:
    ThreadSafeADC0832(IADC0832_SPtr adc0832);
    virtual ~ThreadSafeADC0832() = default;

    void read_value_for_channel(uint channel) override;
    bool is_value_valid_for_channel(uint channel) const override;
    uchar get_value_for_channel(uint channel) const override;
    uint get_number_of_channels() const override;
    uint get_pin_cs() const override;
    uint get_pin_dio() const override;
    uint get_pin_clk() const override;
    void initialize(uint number_of_channels, uint pin_cs, uint pin_dio,
                    uint pin_clk) override;
    void set_adc0832(IADC0832_SPtr adc0832) override;

 private:
    IADC0832_SPtr m_adc0832;
    std::recursive_mutex m_mutex { };
    void atomic(std::function<void()> function);
};

typedef std::shared_ptr<ThreadSafeADC0832> ThreadSafeADC0832_SPtr;

#endif /* IO_THREADSAFE_THREADSAFEADC0832_H_ */
