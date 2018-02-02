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
#include "Publishers/TemperaturesSetCorrectionMessageBusNode.h"
#include "Publishers/TemperaturesPublisher.h"
#include "Publishers/TemperaturesPublisherSettings.h"
#include "Publishers/Messages/TemperaturesMessage.h"
#include "Publishers/Messages/TemperaturesSetCorrectionMessage.h"
#include "Interfaces/Factories/IMessageBusNodeFactory.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMonitor.h"
#include "Interfaces/Monitors/Temperatures/ITemperatureSensorToStringConverter.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMessageHandler.h"
#include "Interfaces/Publishers/ITemperaturesPublisher.h"
#include "Interfaces/Publishers/ITemperaturesPublisherSettings.h"
#include "Interfaces/Factories/ITemperaturesSetCorrectionMessageBusNodeFactory.h"
#include "Factories/TemperaturesSetCorrectionMessageBusNodeFactory.h"

using namespace Hypodermic;
using namespace Sauerteig;
using namespace Sauerteig::Monitors::Temperatures;
using namespace Sauerteig::Publishers;

void Installer::register_components(ContainerBuilder& builder) {
    builder.registerType<Publishers::Messages::TemperaturesMessage>();
    builder.registerType<Publishers::Messages::TemperaturesSetCorrectionMessage>();
    builder.registerType<Publishers::TemperaturesPublisherSettings>()
            .as<Interfaces::Publishers::ITemperaturesPublisherSettings>();

    builder.registerType<Factories::MessageBusNodeFactory<TemperaturesMessageBusNode>>()
            .as<Interfaces::Factories::IMessageBusNodeFactory<TemperaturesMessageBusNode>>();
    builder.registerType<Factories::MessageBusNodeFactory<TemperaturesSetCorrectionMessageBusNode>>()
            .as<Interfaces::Factories::IMessageBusNodeFactory<TemperaturesSetCorrectionMessageBusNode>>();

    builder.registerType<Factories::TemperaturesSetCorrectionMessageBusNodeFactory>()
            .as<Interfaces::Factories::ITemperaturesSetCorrectionMessageBusNodeFactory>();

    builder.registerType<Monitors::Temperatures::TemperaturesMessageHandler>()
            .as<Interfaces::Monitors::Temperatures::ITemperaturesMessageHandler>();
    builder.registerType<Monitors::Temperatures::TemperatureSensorToStringConverter>()
            .as<Interfaces::Monitors::Temperatures::ITemperatureSensorToStringConverter>();

    builder.registerType<Monitors::Temperatures::TemperaturesMonitor>()
            .as<Interfaces::Monitors::Temperatures::ITemperaturesMonitor>().singleInstance();
    builder.registerType<Publishers::TemperaturesPublisherSettings>()
            .as<Interfaces::Publishers::ITemperaturesPublisherSettings>().singleInstance();
    builder.registerType<Publishers::TemperaturesPublisher>().as<Interfaces::Publishers::ITemperaturesPublisher>()
            .singleInstance();
}
