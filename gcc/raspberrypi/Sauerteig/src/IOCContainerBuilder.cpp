/*
 * Installer.cpp
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#include "IOCContainerBuilder.h"
#include "Installer.h"
#include "Common/Installer.h"
#include "Hardware/Installer.h"
#include "Hardware/Abstract/Installer.h"
#include "Hardware/Units/Installer.h"

using namespace Sauerteig;

void IOCContainerBuilder::register_components(Hypodermic::ContainerBuilder& builder) {

    Installer installer { };
    installer.register_components(builder);

    Common::Installer common_installer { };
    common_installer.register_components(builder);

    Hardware::Installer hardware_installer { };
    hardware_installer.register_components(builder);

    Hardware::Abstract::Installer hardware_abstract_installer { };
    hardware_abstract_installer.register_components(builder);

    Hardware::Units::Installer hardware_units_installer { };
    hardware_units_installer.register_components(builder);
}

Container_SPtr IOCContainerBuilder::build() {
    Hypodermic::ContainerBuilder builder;

    register_components(builder);

    Container_SPtr container = builder.build();

    return container;
}
