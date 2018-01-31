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
#include "Publishers/Messages/TemperaturesMessage.h"
#include "Interfaces/Factories/IMessageBusNodeFactory.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMonitor.h"
#include "Interfaces/Monitors/Temperatures/ITemperatureSensorToStringConverter.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMessageHandler.h"
#include "Interfaces/Publishers/ITemperaturesPublisher.h"

using namespace Hypodermic;
using namespace Sauerteig;
using namespace Sauerteig::Monitors::Temperatures;

void Installer::register_components(ContainerBuilder& builder) {
    builder.registerType<Factories::MessageBusNodeFactory<TemperaturesMessageBusNode>>()
            .as<Interfaces::Factories::IMessageBusNodeFactory<TemperaturesMessageBusNode>>();
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
