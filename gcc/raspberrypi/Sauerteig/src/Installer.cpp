/*
 * InstallerCommon.cpp
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#include "Installer.h"
#include "Hypodermic/ContainerBuilder.h"
#include "Factories/TemperaturesMessageBusNodeFactory.h"
#include "Monitors/Temperatures/TemperaturesMonitor.h"
#include "Monitors/Temperatures/TemperatureSensorToStringConverter.h"
#include "Monitors/Temperatures/TemperaturesMessageHandler.h"
#include "Publishers/TemperaturesPublisher.h"
#include "Interfaces/Factories/ITemperaturesMessageBusNodeFactory.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMonitor.h"
#include "Interfaces/Monitors/Temperatures/ITemperatureSensorToStringConverter.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMessageHandler.h"
#include "Interfaces/Publishers/ITemperaturesPublisher.h"
#include "Publishers/Messages/TemperaturesMessage.h"

using namespace Hypodermic;
using namespace Sauerteig;

void Installer::register_components(ContainerBuilder& builder) {
    builder.registerType<Factories::TemperaturesMessageBusNodeFactory>()
            .as<Interfaces::Factories::ITemperaturesMessageBusNodeFactory>();
    builder.registerType<Monitors::Temperatures::TemperaturesMessageHandler>()
            .as<Interfaces::Monitors::Temperatures::ITemperaturesMessageHandler>();
    builder.registerType<Publishers::Messages::TemperaturesMessage>();
    builder.registerType<Monitors::Temperatures::TemperatureSensorToStringConverter>()
            .as<Interfaces::Monitors::Temperatures::ITemperatureSensorToStringConverter>();
    builder.registerType<Monitors::Temperatures::TemperaturesMonitor>()
            .as<Interfaces::Monitors::Temperatures::ITemperaturesMonitor>().singleInstance();
    builder.registerType<Publishers::TemperaturesPublisher>().as<Interfaces::Publishers::ITemperaturesPublisher>()
            .singleInstance();
}
