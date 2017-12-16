//============================================================================
// Name        : Sauerteig.cpp
// Author      : Thomas Schroedter
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <wiringPi.h>
#include <iostream>
#include <memory>
#include <thread>
#include <string>
#include <exception>
#include "Hypodermic/ContainerBuilder.h"
#include "IOCContainerBuilder.h"
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMonitor.h"
#include "Hardware/Abstract/Interfaces/IO/IFlashable.h"
#include "Hardware/Abstract/Interfaces/IO/LEDs/ISSRLEDFlashing.h"
#include "Hardware/Units/Interfaces/IO/Heaters/IHeatingUnit.h"
#include "Hardware/Units/Interfaces/IO/Coolers/ICoolingUnit.h"

int main(void) {

    // TODO use BOOST.DI but needs newer version of gcc
    Sauerteig::IOCContainerBuilder builder { };
    Container_SPtr container = builder.build();

    if (wiringPiSetup() == -1) {
        std::cout << "setup wiringPi failed !\n";
        return -1;
    }

    try {
        ITemperaturesMonitor_SPtr monitor = container
                ->resolve<Sauerteig::Interfaces::Monitors::Temperatures::ITemperaturesMonitor>();
        std::thread thread { std::thread([monitor]() {(*monitor)();}) };

        ILogger_SPtr logger = container->resolve<Common::Interfaces::ILogger>();

        IHeatingUnit_SPtr heading_unit = container->resolve<Hardware::Units::Interfaces::IO::Heaters::IHeatingUnit>();
        ICoolingUnit_SPtr cooling_unit = container->resolve<Hardware::Units::Interfaces::IO::Coolers::ICoolingUnit>();

        while (1) {
            heading_unit->on();
            cooling_unit->on();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            heading_unit->off();
            cooling_unit->off();
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    } catch (std::exception & ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
        return -1;
    }

    return (0);
}
