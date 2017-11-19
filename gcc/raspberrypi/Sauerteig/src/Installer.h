/*
 * Installer.h
 *
 *  Created on: 7 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_INSTALLER_H_
#define SRC_INSTALLER_H_

#include "Hypodermic/ContainerBuilder.h"
#include "./Common/Interfaces/IInstaller.h"

namespace Sauerteig {
class Installer : public Common::Interfaces::IInstaller {
 public:
    Installer() = default;
    virtual ~Installer() = default;

    void register_components(Hypodermic::ContainerBuilder& builder) override;
};
}

#endif /* SRC_INSTALLER_H_ */
