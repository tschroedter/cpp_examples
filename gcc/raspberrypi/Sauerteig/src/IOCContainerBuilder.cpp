/*
 * Installer.cpp
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#include "Interfaces/IO/AnalogeDigitalConverters/IADC0832.h"
#include "IO/AnalogeDigitalConverters/ADC0832.h"
#include "IOCContainerBuilder.h"
#include "IO/InstallerIO.h"

IOCContainerBuilder::IOCContainerBuilder() {

}

IOCContainerBuilder::~IOCContainerBuilder() {
}

void IOCContainerBuilder::register_components(
        Hypodermic::ContainerBuilder& builder) {

    InstallerIO installer_adc0832 { };
    installer_adc0832.register_components(builder);

}

Container_SPtr IOCContainerBuilder::build() {
    Hypodermic::ContainerBuilder builder;

    register_components(builder);

    Container_SPtr container = builder.build();

    return container;
}
