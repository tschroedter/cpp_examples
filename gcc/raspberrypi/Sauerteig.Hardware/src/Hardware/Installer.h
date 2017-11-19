/*
 * InstallerCommon.h
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#ifndef INSTALLERCOMMON_H_
#define INSTALLERCOMMON_H_

#include "Hypodermic/ContainerBuilder.h"
#include "Common/Interfaces/IInstaller.h"

namespace Hardware {
class Installer : public Common::Interfaces::IInstaller {
 public:
    Installer() = default;
    virtual ~Installer() = default;

    void register_components(Hypodermic::ContainerBuilder& builder) override;
};
}

#endif /* INSTALLERCOMMON_H_ */
