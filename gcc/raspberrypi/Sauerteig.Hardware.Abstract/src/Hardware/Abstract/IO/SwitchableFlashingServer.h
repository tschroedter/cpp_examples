/*
 * LEDFlashingServer.h
 *
 *  Created on: 9 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_IO_SWITCHABLEFLASHINGSERVER_H_
#define SRC_HARDWARE_ABSTRACT_IO_SWITCHABLEFLASHINGSERVER_H_

#include "Common/CommonTypes.h"
#include  "../Interfaces/IO/ISwitchable.h"
#include "../Interfaces/IO/ISwitchable.h"
#include "../Interfaces/IO/ISwitchableFlashingServer.h"
#include "../Interfaces/IO/IPulseGeneratoreServer.h"

using namespace Hardware::Abstract;

namespace Hardware {
namespace Abstract {
namespace IO {
class SwitchableFlashingServer : public Interfaces::IO::ISwitchableFlashingServer {
 public:
    SwitchableFlashingServer(IPulseGeneratoreServer_SPtr server);
    virtual ~SwitchableFlashingServer();

    void initialize(ISwitchable_SPtr switchable) override;
    void on() override;
    void off() override;
    bool is_on() const override;

    void start() override;
    void stop() override;
    void set_on_interval_in_msec(uint interval) override;
    void set_off_interval_in_msec(uint interval) override;
    uint get_on_interval_in_msec() override;
    uint get_off_interval_in_msec() override;
    bool is_flashing_enable() const override;

 private:
    ISwitchable_SPtr m_switchable = nullptr;
    IPulseGeneratoreServer_SPtr m_server = nullptr;
};
}
}
}

#endif /* SRC_HARDWARE_ABSTRACT_IO_SWITCHABLEFLASHINGSERVER_H_ */
