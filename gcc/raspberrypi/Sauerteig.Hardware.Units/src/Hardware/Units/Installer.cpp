/*
 * Installer.cpp
 *
 *  Created on: 24 Nov. 2017
 *      Author: tom
 */

#include "Installer.h"
#include "IO/Coolers/Cooler.h"
#include "IO/Coolers/CoolerLED.h"
#include "IO/Coolers/CoolingUnit.h"
#include "IO/Coolers/SSRCooler.h"
#include "IO/Coolers/WiringPiPinCooler.h"
#include "IO/Heaters/Heater.h"
#include "IO/Heaters/HeaterLED.h"
#include "IO/Heaters/HeatingUnit.h"
#include "IO/Heaters/SSRHeater.h"
#include "IO/Heaters/WiringPiPinHeater.h"
#include "IO/Sensors/TemperatureInside.h"
#include "IO/Sensors/TemperatureOutside.h"
#include "Interfaces/IO/Coolers/ICooler.h"
#include "Interfaces/IO/Coolers/ICoolerLED.h"
#include "Interfaces/IO/Coolers/ICoolingUnit.h"
#include "Interfaces/IO/Coolers/ISSRCooler.h"
#include "Interfaces/IO/Coolers/IWiringPiPinCooler.h"
#include "Interfaces/IO/Heaters/IHeater.h"
#include "Interfaces/IO/Heaters/IHeaterLED.h"
#include "Interfaces/IO/Heaters/IHeatingUnit.h"
#include "Interfaces/IO/Heaters/ISSRHeater.h"
#include "Interfaces/IO/Heaters/IWiringPiPinHeater.h"
#include "Interfaces/IO/Sensors/ITemperatureInside.h"
#include "Interfaces/IO/Sensors/ITemperatureOutside.h"

using namespace Hardware::Units;

void Installer::register_components(Hypodermic::ContainerBuilder& builder) {
    builder.registerType<IO::Coolers::WiringPiPinCooler>().as<Interfaces::IO::Coolers::IWiringPiPinCooler>();
    builder.registerType<IO::Coolers::SSRCooler>().as<Interfaces::IO::Coolers::ISSRCooler>();
    builder.registerType<IO::Coolers::Cooler>().as<Interfaces::IO::Coolers::ICooler>();
    builder.registerType<IO::Coolers::CoolerLED>().as<Interfaces::IO::Coolers::ICoolerLED>();
    builder.registerType<IO::Coolers::CoolingUnit>().as<Interfaces::IO::Coolers::ICoolingUnit>().singleInstance();

    builder.registerType<IO::Heaters::WiringPiPinHeater>().as<Interfaces::IO::Heaters::IWiringPiPinHeater>();
    builder.registerType<IO::Heaters::SSRHeater>().as<Interfaces::IO::Heaters::ISSRHeater>();
    builder.registerType<IO::Heaters::Heater>().as<Interfaces::IO::Heaters::IHeater>();
    builder.registerType<IO::Heaters::HeaterLED>().as<Interfaces::IO::Heaters::IHeaterLED>();
    builder.registerType<IO::Heaters::HeatingUnit>().as<Interfaces::IO::Heaters::IHeatingUnit>().singleInstance();

    builder.registerType<IO::Sensors::TemperatureInside>().as<Interfaces::IO::Sensors::ITemperatureInside>()
            .singleInstance();
    builder.registerType<IO::Sensors::TemperatureOutside>().as<Interfaces::IO::Sensors::ITemperatureOutside>()
            .singleInstance();
}

