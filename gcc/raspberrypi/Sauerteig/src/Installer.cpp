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
#include "Monitors/Units/HeaterMonitor.h"
#include "Monitors/Units/HeaterOffMessageHandler.h"
#include "Monitors/Units/HeaterOnMessageHandler.h"
#include "Monitors/Units/CoolerOffMessageHandler.h"
#include "Monitors/Units/CoolerOnMessageHandler.h"
#include "BusNodes/TemperaturesSetCorrectionMessageBusNode.h"
#include "BusNodes/HeaterOffMessageBusNode.h"
#include "BusNodes/HeaterOnMessageBusNode.h"
#include "BusNodes/CoolerOffMessageBusNode.h"
#include "BusNodes/CoolerOnMessageBusNode.h"
#include "Publishers/TemperaturesPublisher.h"
#include "Messages/TemperaturesMessage.h"
#include "Messages/TemperaturesSetCorrectionMessage.h"
#include "Messages/HeaterOffMessage.h"
#include "Messages/HeaterOnMessage.h"
#include "Messages/CoolerOffMessage.h"
#include "Messages/CoolerOnMessage.h"
#include "Interfaces/Factories/IMessageBusNodeFactory.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMonitor.h"
#include "Interfaces/Monitors/Temperatures/ITemperatureSensorToStringConverter.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMessageHandler.h"
#include "Interfaces/Monitors/Units/IHeaterMonitor.h"
#include "Interfaces/Monitors/Units/IHeaterOffMessageHandler.h"
#include "Interfaces/Monitors/Units/IHeaterOnMessageHandler.h"
#include "Interfaces/Monitors/Units/ICoolerOffMessageHandler.h"
#include "Interfaces/Monitors/Units/ICoolerOnMessageHandler.h"
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
    builder.registerType<Messages::HeaterOnMessage>();
    builder.registerType<Messages::HeaterOffMessage>();
    builder.registerType<Messages::CoolerOffMessage>();
    builder.registerType<Messages::CoolerOnMessage>();

    builder.registerType<Factories::MessageBusNodeFactory<TemperaturesMessageBusNode>>()
            .as<Interfaces::Factories::IMessageBusNodeFactory<TemperaturesMessageBusNode>>();
    builder.registerType<Factories::MessageBusNodeFactory<HeaterOffMessageBusNode>>()
            .as<Interfaces::Factories::IMessageBusNodeFactory<HeaterOffMessageBusNode>>();
    builder.registerType<Factories::MessageBusNodeFactory<HeaterOnMessageBusNode>>()
            .as<Interfaces::Factories::IMessageBusNodeFactory<HeaterOnMessageBusNode>>();
    builder.registerType<Factories::MessageBusNodeFactory<CoolerOffMessageBusNode>>()
            .as<Interfaces::Factories::IMessageBusNodeFactory<CoolerOffMessageBusNode>>();
    builder.registerType<Factories::MessageBusNodeFactory<CoolerOnMessageBusNode>>()
            .as<Interfaces::Factories::IMessageBusNodeFactory<CoolerOnMessageBusNode>>();

    /*
    builder.registerType<Factories::MessageBusNodeFactory<TemperaturesSetCorrectionMessageBusNode>>()
            .as<Interfaces::Factories::IMessageBusNodeFactory<TemperaturesSetCorrectionMessageBusNode>>();
            */

    builder.registerType<Factories::TemperaturesSetCorrectionMessageBusNodeFactory>()
            .as<Interfaces::Factories::ITemperaturesSetCorrectionMessageBusNodeFactory>();

    builder.registerType<Monitors::Settings::SettingsMonitor>()
                .as<Interfaces::Monitors::Settings::ISettingsMonitor>();
    builder.registerType<Monitors::Units::HeaterMonitor>()
                .as<Interfaces::Monitors::Units::IHeaterMonitor>();

    builder.registerType<Monitors::Temperatures::TemperaturesMessageHandler>()
            .as<Interfaces::Monitors::Temperatures::ITemperaturesMessageHandler>();
    builder.registerType<Monitors::Units::HeaterOffMessageHandler>()
            .as<Interfaces::Monitors::Units::IHeaterOffMessageHandler>();
    builder.registerType<Monitors::Units::HeaterOnMessageHandler>()
            .as<Interfaces::Monitors::Units::IHeaterOnMessageHandler>();
    builder.registerType<Monitors::Units::CoolerOffMessageHandler>()
            .as<Interfaces::Monitors::Units::ICoolerOffMessageHandler>();
    builder.registerType<Monitors::Units::CoolerOnMessageHandler>()
            .as<Interfaces::Monitors::Units::ICoolerOnMessageHandler>();

    builder.registerType<Monitors::Temperatures::TemperatureSensorToStringConverter>()
            .as<Interfaces::Monitors::Temperatures::ITemperatureSensorToStringConverter>();

    builder.registerType<Settings>()
            .as<Interfaces::ISettings>().singleInstance();
    builder.registerType<Monitors::Temperatures::TemperaturesMonitor>()
            .as<Interfaces::Monitors::Temperatures::ITemperaturesMonitor>().singleInstance();
    builder.registerType<Publishers::TemperaturesPublisher>().as<Interfaces::Publishers::ITemperaturesPublisher>()
            .singleInstance();
}
