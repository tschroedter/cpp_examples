/*
 * Installer.cpp
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#include "IOCContainerBuilder.h"
#include "IO/Installer.h"
#include "Hardware/HarwareInstaller.h"

IOCContainerBuilder::IOCContainerBuilder() {

}

IOCContainerBuilder::~IOCContainerBuilder() {
}

void IOCContainerBuilder::register_components(
        Hypodermic::ContainerBuilder& builder) {

    Installer installer { };
    installer.register_components(builder);

    HardwareInstaller hardware_installer { };
    hardware_installer.register_components(builder);
}

Container_SPtr IOCContainerBuilder::build() {
    Hypodermic::ContainerBuilder builder;

    register_components(builder);

    Container_SPtr container = builder.build();

    return container;
}
