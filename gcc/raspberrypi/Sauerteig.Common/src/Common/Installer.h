/*
 * CommonInstaller.h
 *
 *  Created on: 18 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_COMMON_INSTALLER_H_
#define SRC_COMMON_INSTALLER_H_

#include "Hypodermic/ContainerBuilder.h"
#include "Interfaces/IInstaller.h"

namespace Common {
class Installer : public Interfaces::IInstaller {
 public:
    Installer() = default;
    virtual ~Installer() = default;

    void register_components(Hypodermic::ContainerBuilder& builder) override;
};
}

#endif /* SRC_COMMON_INSTALLER_H_ */
