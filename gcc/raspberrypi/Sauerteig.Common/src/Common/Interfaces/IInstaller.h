/*
 * IInstaller.h
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_SAUERTEIG_COMMON_INTERFACES_IINSTALLER_H_
#define SRC_SAUERTEIG_COMMON_INTERFACES_IINSTALLER_H_

#include <Hypodermic/ContainerBuilder.h>

using namespace Hypodermic;

namespace Common {
namespace Interfaces {
class IInstaller {
 public:
    virtual ~IInstaller() = default;

    virtual void register_components(ContainerBuilder& builder) = 0;
};
}
}

#endif /* SRC_SAUERTEIG_COMMON_INTERFACES_IINSTALLER_H_ */
