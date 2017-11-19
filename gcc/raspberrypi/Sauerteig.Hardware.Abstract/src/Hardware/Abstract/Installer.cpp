/*
 * InstallerCommon.cpp
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#include "Hypodermic/ContainerBuilder.h"
#include "Hypodermic/ComponentContext.h"

#include "Installer.h"
#include "IO/PulseGeneratoreServer.h"
#include "IO/WiringPiPin.h"
#include "IO/SwitchableFlashingServer.h"
#include "IO/AnalogeDigitalConverters/ThreadSafe/ThreadSafeADC0832.h"
#include "IO/LEDs/SSRLED.h"
#include "IO/LEDs/SSRLEDFlashing.h"
#include "IO/Sensors/TemperatureInside.h"
#include "IO/Sensors/TemperatureOutside.h"
#include "IO/Sensors/ADCTmp36.h"
#include "IO/SerialShiftRegister/ThreadSafe/ThreadSafe74HC595.h"
#include "IO/SerialShiftRegister/SerialShiftRegisterManager.h"
#include "IO/SerialShiftRegister/ThreadSafe/ThreadSafeSerialShiftRegisterManager.h"
#include "IO/SerialShiftRegister/SSROutputs.h"
#include "Interfaces/IO/ISwitchableFlashingServer.h"
#include "Interfaces/IO/AnalogeDigitalConverters/IADCInputs.h"
#include "Interfaces/IO/AnalogeDigitalConverters/ThreadSafe/IThreadSafeADC0832.h"
#include "Interfaces/IO/LEDs/ILED.h"
#include "Interfaces/IO/LEDs/ISSRLED.h"
#include "Interfaces/IO/LEDs/ISSRLEDFlashing.h"
#include "Interfaces/IO/IPulseGeneratoreServer.h"
#include "Interfaces/IO/IWiringPiPin.h"
#include "Interfaces/IO/Sensors/ITemperatureInside.h"
#include "Interfaces/IO/Sensors/ITemperatureOutside.h"
#include "Interfaces/IO/Sensors/IADCTmp36.h"
#include "Interfaces/IO/SerialShiftRegister/ThreadSafe/IThreadSafe74HC595.h"
#include "Interfaces/IO/SerialShiftRegister/ISerialShiftRegisterManager.h"
#include "Interfaces/IO/SerialShiftRegister/ThreadSafe/IThreadSafeSerialShiftRegisterManager.h"
#include "Interfaces/IO/SerialShiftRegister/ISSROutputs.h"
#include "Interfaces/IO/Heaters/ISSRHeater.h"
#include "Interfaces/IO/Heaters/IWiringPiPinHeater.h"
#include "IO/AnalogeDigitalConverters/ADCInputs.h"
#include "IO/LEDs/WiringPiPinLED.h"
#include "IO/Heaters/SSRHeater.h"
#include "IO/Heaters/WiringPiPinHeater.h"

using namespace Hardware::Abstract;

void Installer::register_components(Hypodermic::ContainerBuilder& builder) {
    builder.registerType<IO::AnalogeDigitalConverters::ADCInputs>()
            .as<Interfaces::IO::AnalogeDigitalConverters::IADCInputs>()
            .singleInstance();
    builder.registerType<IO::SerialShiftRegister::SSROutputs>()
            .as<Interfaces::IO::SerialShiftRegister::ISSROutputs>()
            .singleInstance();
    builder
            .registerType<
                    IO::SerialShiftRegister::ThreadSafe::ThreadSafeSerialShiftRegisterManager>()
            .as<
                    Interfaces::IO::SerialShiftRegister::ThreadSafe::IThreadSafeSerialShiftRegisterManager>();
    builder
            .registerType<
                    IO::AnalogeDigitalConverters::ThreadSafe::ThreadSafeADC0832>()
            .as<
                    Interfaces::IO::AnalogeDigitalConverters::ThreadSafe::IThreadSafeADC0832>();
    builder.registerType<IO::LEDs::WiringPiPinLED>()
            .as<Interfaces::IO::LEDs::ILED>();
    builder.registerType<IO::PulseGeneratoreServer>()
            .as<Interfaces::IO::IPulseGeneratoreServer>();
    builder.registerType<IO::WiringPiPin>().as<Interfaces::IO::IWiringPiPin>();
    builder.registerType<IO::Sensors::TemperatureInside>()
            .as<Interfaces::IO::Sensors::ITemperatureInside>();
    builder.registerType<IO::Sensors::TemperatureOutside>()
            .as<Interfaces::IO::Sensors::ITemperatureOutside>();
    builder.registerType<IO::SerialShiftRegister::ThreadSafe::ThreadSafe74HC595>()
            .as<
                    Interfaces::IO::SerialShiftRegister::ThreadSafe::IThreadSafe74HC595>();
    builder.registerType<IO::SerialShiftRegister::SerialShiftRegisterManager>()
            .as<Interfaces::IO::SerialShiftRegister::ISerialShiftRegisterManager>();
    builder.registerType<IO::LEDs::SSRLED>().as<Interfaces::IO::LEDs::ISSRLED>();
    builder.registerType<IO::Sensors::ADCTmp36>()
            .as<Interfaces::IO::Sensors::IADCTmp36>();
    builder.registerType<IO::SwitchableFlashingServer>()
            .as<Interfaces::IO::ISwitchableFlashingServer>();
    builder.registerType<IO::LEDs::SSRLEDFlashing>()
            .as<Interfaces::IO::LEDs::ISSRLEDFlashing>();
    builder.registerType<IO::Heaters::SSRHeater>()
            .as<Interfaces::IO::Heaters::ISSRHeater>();
    builder.registerType<IO::Heaters::WiringPiPinHeater>()
            .as<Interfaces::IO::Heaters::IWiringPiPinHeater>();
}
