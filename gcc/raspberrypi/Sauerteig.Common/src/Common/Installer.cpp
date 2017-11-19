/*
 * CommonInstaller.cpp
 *
 *  Created on: 18 Nov. 2017
 *      Author: tom
 */

#include "Installer.h"

#include "Hypodermic/ContainerBuilder.h"
#include "Logger.h"
#include "Interfaces/ILogger.h"

using namespace Common;

void Installer::register_components(Hypodermic::ContainerBuilder& builder) {
    builder.registerType<Logger>().as<Interfaces::ILogger>();
}

