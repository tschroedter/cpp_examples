/*
 * IInstaller.h
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#ifndef IINSTALLER_H_
#define IINSTALLER_H_

#include <Hypodermic/ContainerBuilder.h>

class IInstaller {
 public:
    virtual ~IInstaller() = default;

    virtual void register_components(Hypodermic::ContainerBuilder& builder) = 0;
};

#endif /* IINSTALLER_H_ */
