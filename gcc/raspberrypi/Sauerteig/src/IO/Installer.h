/*
 * Installer.h
 *
 *  Created on: 7 Nov. 2017
 *      Author: tom
 */

#ifndef IO_INSTALLER_H_
#define IO_INSTALLER_H_

#include "Hypodermic/ContainerBuilder.h"
#include "./Common/Interfaces/IInstaller.h"

class Installer : public IInstaller {
 public:
    Installer() = default;
    virtual ~Installer() = default;

    void register_components(Hypodermic::ContainerBuilder& builder) override;
};

#endif /* IO_INSTALLER_H_ */
