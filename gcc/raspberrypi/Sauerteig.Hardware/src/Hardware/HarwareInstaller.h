/*
 * InstallerCommon.h
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#ifndef INSTALLERCOMMON_H_
#define INSTALLERCOMMON_H_

#include "Hypodermic/ContainerBuilder.h"
#include "./Common/Interfaces/IInstaller.h"

class HardwareInstaller : public IInstaller {
 public:
    HardwareInstaller() = default;
    virtual ~HardwareInstaller() = default;

    void register_components(Hypodermic::ContainerBuilder& builder) override;
};

#endif /* INSTALLERCOMMON_H_ */
