/*
 * InstallerCommon.cpp
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#include "Installer.h"
#include "Hypodermic/ContainerBuilder.h"
#include "Factories/MessageBusNodeFactory.h"
#include "Monitors/Temperatures/TemperaturesMonitor.h"
#include "Monitors/Temperatures/TemperatureSensorToStringConverter.h"
#include "Monitors/Temperatures/TemperaturesMessageHandler.h"
#include "Monitors/Settings/SettingsMonitor.h"
#include "BusNodes/TemperaturesSetCorrectionMessageBusNode.h"
#include "Publishers/TemperaturesPublisher.h"
#include "Messages/TemperaturesMessage.h"
#include "Messages/TemperaturesSetCorrectionMessage.h"
#include "Interfaces/Factories/IMessageBusNodeFactory.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMonitor.h"
#include "Interfaces/Monitors/Temperatures/ITemperatureSensorToStringConverter.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMessageHandler.h"
#include "Interfaces/Publishers/ITemperaturesPublisher.h"
#include "Interfaces/Factories/ITemperaturesSetCorrectionMessageBusNodeFactory.h"
#include "Interfaces/Monitors/Settings/ISettingsMonitor.h"
#include "Factories/TemperaturesSetCorrectionMessageBusNodeFactory.h"
#include "Interfaces/ISettings.h"
#include "Settings.h"

using namespace Hypodermic;
using namespace Sauerteig;
using namespace Sauerteig::Monitors::Temperatures;
using namespace Sauerteig::Publishers;

void Installer::register_components(ContainerBuilder& builder) {
    builder.registerType<Messages::TemperaturesMessage>();
    builder.registerType<Messages::TemperaturesSetCorrectionMessage>();

    builder.registerType<Factories::MessageBusNodeFactory<TemperaturesMessageBusNode>>()
            .as<Interfaces::Factories::IMessageBusNodeFactory<TemperaturesMessageBusNode>>();
    builder.registerType<Factories::MessageBusNodeFactory<TemperaturesSetCorrectionMessageBusNode>>()
            .as<Interfaces::Factories::IMessageBusNodeFactory<TemperaturesSetCorrectionMessageBusNode>>();

    builder.registerType<Factories::TemperaturesSetCorrectionMessageBusNodeFactory>()
            .as<Interfaces::Factories::ITemperaturesSetCorrectionMessageBusNodeFactory>();

    builder.registerType<Monitors::Settings::SettingsMonitor>()
                .as<Interfaces::Monitors::Settings::ISettingsMonitor>();
    builder.registerType<Monitors::Temperatures::TemperaturesMessageHandler>()
            .as<Interfaces::Monitors::Temperatures::ITemperaturesMessageHandler>();
    builder.registerType<Monitors::Temperatures::TemperatureSensorToStringConverter>()
            .as<Interfaces::Monitors::Temperatures::ITemperatureSensorToStringConverter>();

    builder.registerType<Settings>()
            .as<Interfaces::ISettings>().singleInstance();
    builder.registerType<Monitors::Temperatures::TemperaturesMonitor>()
            .as<Interfaces::Monitors::Temperatures::ITemperaturesMonitor>().singleInstance();
    builder.registerType<Publishers::TemperaturesPublisher>().as<Interfaces::Publishers::ITemperaturesPublisher>()
            .singleInstance();
}
