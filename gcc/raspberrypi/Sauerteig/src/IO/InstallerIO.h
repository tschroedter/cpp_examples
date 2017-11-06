/*
 * InstallerCommon.h
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#ifndef INSTALLERCOMMON_H_
#define INSTALLERCOMMON_H_

#include "Hypodermic/ContainerBuilder.h"
#include "../Interfaces/IInstaller.h"

class InstallerIO : public IInstaller {
 public:
    InstallerIO();
    virtual ~InstallerIO();

    void register_components(Hypodermic::ContainerBuilder& builder) override;
};

#endif /* INSTALLERCOMMON_H_ */
