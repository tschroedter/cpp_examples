/*
 * Installer.h
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#ifndef IOCCONTAINERBUILDER_H_
#define IOCCONTAINERBUILDER_H_

#include "Hypodermic/ContainerBuilder.h"

typedef std::shared_ptr<Hypodermic::Container> Container_SPtr;

class IOCContainerBuilder {
 public:
    IOCContainerBuilder();
    virtual ~IOCContainerBuilder();

    Container_SPtr build();

 private:
    void register_components(Hypodermic::ContainerBuilder& builder);
};

#endif /* IOCCONTAINERBUILDER_H_ */
