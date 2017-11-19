/*
 * PulseGeneratoreServer.h
 *
 *  Created on: 10 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_IO_PULSEGENERATORESERVER_H_
#define SRC_HARDWARE_ABSTRACT_IO_PULSEGENERATORESERVER_H_

#include <thread>
#include <atomic>
#include <iostream>
#include "../Interfaces/IO/IPulseGeneratoreServer.h"
#include "../Interfaces/IO/ISwitchable.h"

using namespace Hardware::Abstract;

namespace Hardware {
namespace Abstract {
namespace IO {
class PulseGeneratoreServer : public Interfaces::IO::IPulseGeneratoreServer {
 public:
    PulseGeneratoreServer();
    virtual ~PulseGeneratoreServer();

    void operator()() override {
        this->run();
    }

    void initialize(ISwitchable_SPtr switchable) override;

    void on() override;
    void off() override;bool is_on() const override;

    void start() override;
    void stop() override;
    void set_on_interval_in_msec(uint interval) override;
    void set_off_interval_in_msec(uint interval) override;
    uint get_on_interval_in_msec() override;
    uint get_off_interval_in_msec() override;bool is_flashing_enable() const
            override;

    void do_one_flash();

 private:
    ISwitchable_SPtr m_switchable;
    std::atomic_bool m_done { };
    std::atomic_bool m_is_flashing_enabled { };
    std::atomic_uint m_interval_on_in_msec { 1000 };
    std::atomic_uint m_interval_off_in_msec { 1000 };
    std::thread m_worker { };

    void run();
};
}
}
}

#endif /* SRC_HARDWARE_ABSTRACT_IO_PULSEGENERATORESERVER_H_ */
