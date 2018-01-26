/*
 * InstallerCommon.cpp
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#include "Installer.h"
#include "Hypodermic/ContainerBuilder.h"
#include "IO/Sensors/Tmp36.h"
#include "IO/Sensors/Tmp36Logic.h"
#include "IO/AnalogeDigitalConverters/ADC0832.h"
#include "IO/SerialShiftRegister/SSR74HC595.h"
#include "Interfaces/IO/Sensors/ITmp36.h"
#include "Interfaces/IO/Sensors/ITmp36Logic.h"
#include "Interfaces/IO/AnalogeDigitalConverters/IADC0832.h"
#include "Interfaces/IO/SerialShiftRegister/I74HC595.h"

using namespace Hypodermic;
using namespace Hardware;

void Installer::register_components(ContainerBuilder& builder) {

    builder.registerType<IO::AnalogeDigitalConverters::ADC0832>().as<Interfaces::IO::AnalogeDigitalConverters::IADC0832>();
    builder.registerType<IO::Sensors::Tmp36>().as<Interfaces::IO::Sensors::ITmp36>();
    builder.registerType<IO::Sensors::Tmp36Logic>().as<Interfaces::IO::Sensors::ITmp36Logic>();
    builder.registerType<IO::SerialShiftRegisters::SSR74HC595>().as<Interfaces::IO::SerialShiftRegister::I74HC595>();
}
