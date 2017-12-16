/*
 * Installer.h
 *
 *  Created on: 24 Nov. 2017
 *      Author: tom
 */

#ifndef HARDWARE_UNITS_IO_INSTALLER_H_
#define HARDWARE_UNITS_IO_INSTALLER_H_

#include "Hypodermic/ContainerBuilder.h"
#include "Common/Interfaces/IInstaller.h"

namespace Hardware {
namespace Units {
class Installer : public Common::Interfaces::IInstaller {
 public:
    Installer() = default;
    virtual ~Installer() = default;

    void register_components(Hypodermic::ContainerBuilder& builder) override;
};
}
}

#endif /* HARDWARE_UNITS_IO_INSTALLER_H_ */
