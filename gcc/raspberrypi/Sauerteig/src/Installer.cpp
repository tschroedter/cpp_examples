/*
 * InstallerCommon.cpp
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#include "Installer.h"
#include "Hypodermic/ContainerBuilder.h"
#include "Monitors/TemperaturesMonitor.h"
#include "Monitors/TemperatureSensorToStringConverter.h"
#include "Interfaces/Monitors/ITemperaturesMonitor.h"
#include "Interfaces/Monitors/ITemperatureSensorToStringConverter.h"

using namespace Sauerteig;

void Installer::register_components(Hypodermic::ContainerBuilder& builder) {
    builder.registerType<Monitors::TemperatureSensorToStringConverter>()
            .as<Interfaces::Monitors::ITemperatureSensorToStringConverter>();
    builder.registerType<Monitors::TemperaturesMonitor>().as<Interfaces::Monitors::ITemperaturesMonitor>()
            .singleInstance();
}
