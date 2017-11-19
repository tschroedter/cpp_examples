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
#include "Interfaces/Monitors/ITemperaturesMonitor.h"
#include "Hardware/Abstract/Interfaces/IO/IFlashable.h"
#include "Hardware/Abstract/Interfaces/IO/LEDs/ISSRLEDFlashing.h"

int main(void) {

    // TODO use BOOST.DI
    Sauerteig::IOCContainerBuilder builder { };
    Container_SPtr container = builder.build();

    if (wiringPiSetup() == -1) {
        std::cout << "setup wiringPi failed !\n";
        return -1;
    }

    try {
        using namespace Hardware::Abstract::Interfaces::IO::LEDs;

        ISSRLEDFlashing_SPtr led_power = container->resolve<ISSRLEDFlashing>();
        led_power->initialize((ssroutputpin) 0);
        led_power->start();

        ISSRLEDFlashing_SPtr led_cooling =
                container->resolve<ISSRLEDFlashing>();
        led_cooling->initialize((ssroutputpin) 1);
        led_cooling->set_on_interval_in_msec(2000);
        led_cooling->set_off_interval_in_msec(2000);
        led_cooling->start();

        ISSRLEDFlashing_SPtr led_heating =
                container->resolve<ISSRLEDFlashing>();
        led_heating->initialize((ssroutputpin) 2);
        led_heating->set_on_interval_in_msec(3000);
        led_heating->set_off_interval_in_msec(3000);
        led_heating->start();

        ITemperaturesMonitor_SPtr monitor =
                container
                        ->resolve<
                                Sauerteig::Interfaces::Monitors::ITemperaturesMonitor>();
        std::thread thread { std::thread([monitor]() {(*monitor)();}) };

        ILogger_SPtr logger = container->resolve<Common::Interfaces::ILogger>();

        while (1) {
            logger->info("main...");
            std::this_thread::sleep_for(std::chrono::seconds(10));
        }
    } catch (std::exception & ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
        return -1;
    }

    return (0);
}
