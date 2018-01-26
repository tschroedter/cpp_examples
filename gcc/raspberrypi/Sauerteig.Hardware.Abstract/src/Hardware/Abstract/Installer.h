/*
 * InstallerCommon.h
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_HARDWARE_ABSTRACT_INSTALLERCOMMON_H_
#define SRC_HARDWARE_ABSTRACT_INSTALLERCOMMON_H_

#include "Hypodermic/ContainerBuilder.h"
#include "./Common/Interfaces/IInstaller.h"

using namespace Common::Interfaces;

namespace Hardware {
namespace Abstract {
class Installer : public IInstaller {
 public:
    Installer() = default;
    virtual ~Installer() = default;

    void register_components(Hypodermic::ContainerBuilder& builder) override;
};
}
}

#endif /* SRC_HARDWARE_ABSTRACT_INSTALLERCOMMON_H_ */
