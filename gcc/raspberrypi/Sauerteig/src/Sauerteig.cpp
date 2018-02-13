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
#include <uuid/uuid.h>
#include "Hypodermic/ContainerBuilder.h"
#include "IOCContainerBuilder.h"
#include "Common/CommonTypes.h"
#include "Common/Interfaces/ILogger.h"
#include "Common/LogLevel.h"
#include "Common/Interfaces/IThreadInformationProvider.h"
#include "Interfaces/Monitors/Temperatures/ITemperaturesMonitor.h"
#include "Interfaces/Monitors/Settings/ISettingsMonitor.h"
#include "Interfaces/Monitors/Units/IHeaterMonitor.h"
#include "Interfaces/Publishers/ITemperaturesPublisher.h"
#include "Interfaces/Factories/ITemperaturesSetCorrectionMessageBusNodeFactory.h"
#include "Hardware/Abstract/Interfaces/IO/IFlashable.h"
#include "Hardware/Abstract/Interfaces/IO/LEDs/ISSRLEDFlashing.h"
#include "Hardware/Units/Interfaces/IO/Heaters/IHeatingUnit.h"
#include "Hardware/Units/Interfaces/IO/Coolers/ICoolingUnit.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Subscribtions/SubscribtionManager.h"
#include "InMemoryBus/Subscribtions/MessageToSubscribers/IMessageToSubscribersRepository.h"
#include "InMemoryBus/Subscribtions/Subscribers/Factories/ISubscriberInformationEntityFactory.h"
#include "InMemoryBus/Subscribtions/MessageToSubscribers/IMessageToSubscribersEntityFactory.h"
#include "InMemoryBus/Subscribtions/Subscribers/UnknownSubscriberInformationEntityEntity.h"
#include "InMemoryBus/Notifiers/INotifierThreadPool.h"
#include "InMemoryBus/Notifiers/Failed/IFailedMessageQueueProcessor.h"

#include "Interfaces/ISettings.h"
#include "Monitors/Temperatures/TemperaturesMessageHandler.h"
#include "Messages/HeaterOffMessage.h"
#include "Messages/HeaterOnMessage.h"
#include "Messages/TemperaturesSetCorrectionMessage.h"

using namespace std;

void make_linker_happy() {
    uuid_t id;
    uuid_generate(id);

    char *string = new char[100];
    uuid_unparse(id, string);

    int result = uuid_parse(string, id);
    std::cout << result << std::endl;

    uuid_t other;
    uuid_copy(other, id);

    std::cout << string << std::endl;
    bool compare = uuid_compare(id, other) == 0;

    std::cout << compare << std::endl;
}

int main(void) {
    make_linker_happy();

    // TODO use BOOST.DI but needs newer version of gcc
    Sauerteig::IOCContainerBuilder builder { };
    Container_SPtr container = builder.build();

    if (wiringPiSetup() == -1) {
        std::cout << "setup wiringPi failed !\n";
        return -1;
    }

    try {
        auto logger = container->resolve<Common::Interfaces::ILogger>();
        logger->set_prefix("Sauerteig");
        logger->set_log_level(Common::LogLevel::Enum::INFO);

        auto provider = container->resolve<Common::Interfaces::IThreadInformationProvider>();
        logger->info("Sauerteig Main PID: " + provider->get_thread_process_id_as_string());

        auto bus = container->resolve<InMemoryBus::IBus>();

        // start ibus
        auto notifier_pool = container->resolve<::InMemoryBus::Notifiers::INotifierThreadPool>();
        notifier_pool->initialize(4);
        auto failed_messages_processor = container
                ->resolve<::InMemoryBus::Notifiers::Failed::IFailedMessageQueueProcessor>();
        failed_messages_processor->initialize();

        // Sauerteig init...
        ITemperaturesPublisher_SPtr temperatures_publisher = container
                ->resolve<Sauerteig::Interfaces::Publishers::ITemperaturesPublisher>();
        std::thread temperatures_publisher_thread { std::thread(
                [temperatures_publisher]() {(*temperatures_publisher)();}) };

        ITemperaturesMonitor_SPtr temperatures_monitor = container
                ->resolve<Sauerteig::Interfaces::Monitors::Temperatures::ITemperaturesMonitor>();
        std::thread temperatures_monitor_thread { std::thread([temperatures_monitor]() {(*temperatures_monitor)();}) };

        ISettingsMonitor_SPtr settings_monitor = container
                ->resolve<Sauerteig::Interfaces::Monitors::Settings::ISettingsMonitor>();
        std::thread settings_monitor_thread { std::thread([settings_monitor]() {(*settings_monitor)();}) };

        IHeaterMonitor_SPtr heater_monitor = container
                ->resolve<Sauerteig::Interfaces::Monitors::Units::IHeaterMonitor>();
        std::thread heater_monitor_thread { std::thread([heater_monitor]() {(*heater_monitor)();}) };

        // Sauerteig run...
        auto message1 = make_shared<Sauerteig::Messages::TemperaturesSetCorrectionMessage>();
        message1->inside_average_value_correction = (celsius) 100.0;
        message1->outside_average_value_correction = (celsius) 200.0;
        bus->publish(message1);

        auto message2 = make_shared<Sauerteig::Messages::HeaterOffMessage>();
        bus->publish(message2);

        // std::this_thread::sleep_for(std::chrono::seconds(5));

        auto message3 = make_shared<Sauerteig::Messages::HeaterOnMessage>();
        bus->publish(message3);

        // Sauerteig run...
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

