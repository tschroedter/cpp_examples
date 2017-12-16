/*
 * InstallerCommon.cpp
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#include "Installer.h"
#include "Hypodermic/ContainerBuilder.h"
#include "Monitors/Temperatures/TemperaturesMonitor.h"
#include "Monitors/Temperatures/TemperatureSensorToStringConverter.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMonitor.h"
#include "Interfaces/Monitors/Temperatures/ITemperatureSensorToStringConverter.h"

using namespace Sauerteig;

void Installer::register_components(Hypodermic::ContainerBuilder& builder) {
    builder.registerType<Monitors::Temperatures::TemperatureSensorToStringConverter>()
            .as<Interfaces::Monitors::Temperatures::ITemperatureSensorToStringConverter>();
    builder.registerType<Monitors::Temperatures::TemperaturesMonitor>()
            .as<Interfaces::Monitors::Temperatures::ITemperaturesMonitor>().singleInstance();
}
