/*
 * IInstaller.h
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#ifndef SAUERTEIG_COMMON_INTERFACES_IINSTALLER_H_
#define SAUERTEIG_COMMON_INTERFACES_IINSTALLER_H_

#include <Hypodermic/ContainerBuilder.h>

namespace Common {
namespace Interfaces {
class IInstaller {
 public:
    virtual ~IInstaller() = default;

    virtual void register_components(Hypodermic::ContainerBuilder& builder) = 0;
};
}
}

#endif /* IINSTALLER_H_ */
