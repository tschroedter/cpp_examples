/*
 * InstallerCommon.cpp
 *
 *  Created on: 2 Nov. 2017
 *      Author: tom
 */

#include "HarwareInstaller.h"
#include "Hypodermic/ContainerBuilder.h"
#include "IO/Sensors/Tmp36.h"
#include "IO/AnalogeDigitalConverters/ADC0832.h"
#include "IO/AnalogeDigitalConverters/ThreadSafe/ThreadSafeADC0832.h"
#include "IO/SerialShiftRegister/SSR74HC595.h"
#include "Interfaces/IO/Sensors/ITmp36.h"
#include "Interfaces/IO/AnalogeDigitalConverters/IADC0832.h"
#include "Interfaces/IO/AnalogeDigitalConverters/ThreadSafe/IThreadSafeADC0832.h"
#include "Interfaces/IO/SerialShiftRegister/I74HC595.h"

void HardwareInstaller::register_components(
        Hypodermic::ContainerBuilder& builder) {
    builder.registerType<ADC0832>().as<IADC0832>();
    builder.registerType<ThreadSafeADC0832>().as<IThreadSafeADC0832>();
    builder.registerType<Tmp36>().as<ITmp36>();
    builder.registerType<SSR74HC595>().as<I74HC595>();
}
