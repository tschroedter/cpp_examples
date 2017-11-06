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
#include <vector>
#include <string.h>
#include "Hypodermic/ContainerBuilder.h"
#include "IOCContainerBuilder.h"
#include "Interfaces/IO/Sensors/ITmp36Console.h"
#include "Interfaces/IO/Monitors/ITemperaturesMonitor.h"

#define CHANNEL_0 ((uint) 0)
#define CHANNEL_1 ((uint) 1)

int main(void) {

// todo use BOOST.DI

    IOCContainerBuilder builder { };
    Container_SPtr container = builder.build();

    if (wiringPiSetup() == -1) {
        std::cout << "setup wiringPi failed !\n";
        return -1;
    }

    ITemperaturesMonitor_SPtr monitor =
            container->resolve<ITemperaturesMonitor>();
    std::thread thread { std::thread([monitor]() {(*monitor)();}) };

    while (1) {
        delay(10000);
    }

    return (0);
}
