/*
 * Installer.h
 *
 *  Created on: 9 Jan. 2018
 *      Author: tom
 */

#ifndef INMEMORYBUS_INSTALLER_H_
#define INMEMORYBUS_INSTALLER_H_

#include "Hypodermic/ContainerBuilder.h"
#include "Common/Interfaces/IInstaller.h"

namespace InMemoryBus {

class Installer : public Common::Interfaces::IInstaller {
 public:
    Installer() = default;
    virtual ~Installer() = default;

    void register_components(Hypodermic::ContainerBuilder& builder) override;
};
}

#endif /* INMEMORYBUS_INSTALLER_H_ */
