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
#include "Interfaces/IThreadInformationProvider.h"
#include "ThreadInformationProvider.h"

using namespace Common;

void Installer::register_components(Hypodermic::ContainerBuilder& builder) {
    builder.registerType<Logger>().as<Interfaces::ILogger>();
    builder.registerType<ThreadInformationProvider>().as<Interfaces::IThreadInformationProvider>();
}

