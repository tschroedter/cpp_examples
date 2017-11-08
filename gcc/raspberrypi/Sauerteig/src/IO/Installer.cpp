/*
 * InstallerCommon.cpp
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#include "Installer.h"
#include "Hypodermic/ContainerBuilder.h"
#include "Sensors/TemperatureInside.h"
#include "Sensors/TemperatureOutside.h"
#include "Sensors/Tmp36Console.h"
#include "Monitors/TemperaturesMonitor.h"
#include "Monitors/TemperatureSensorToStringConverter.h"
#include "AnalogeDigitalConverters/ADCTemperatures.h"
#include "../Interfaces/IO/Sensors/ITmp36Console.h"
#include "../Interfaces/IO/Sensors/ITemperatureInside.h"
#include "../Interfaces/IO/Sensors/ITemperatureOutside.h"
#include "../Interfaces/IO/Monitors/ITemperaturesMonitor.h"
#include "../Interfaces/IO/Monitors/ITemperatureSensorToStringConverter.h"


void Installer::register_components(Hypodermic::ContainerBuilder& builder) {
    builder.registerType<Tmp36Console>().as<ITmp36Console>();
    builder.registerType<Tmp36Console>().as<ITmp36Console>();
    builder.registerType<ADCTemperatures>().as<IADCTemperatures>()
            .singleInstance();
    builder.registerType<TemperatureInside>().as<ITemperatureInside>();
    builder.registerType<TemperatureOutside>().as<ITemperatureOutside>();
    builder.registerType<TemperatureSensorToStringConverter>()
            .as<ITemperatureSensorToStringConverter>();
    builder.registerType<TemperaturesMonitor>().as<ITemperaturesMonitor>()
            .singleInstance();
}
