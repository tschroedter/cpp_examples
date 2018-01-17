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
#include "Interfaces/Monitors/Temperatures/ITemperaturesMonitor.h"
#include "Interfaces/Publishers/ITemperaturesPublisher.h"
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
#include "Monitors/Temperatures/TemperaturesMessageHandler.h"

void make_linker_happy()
{
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
        auto mtse_vector = container->resolve<IMessageToSubscribersEntityVector>();
        auto msg_repo = container->resolve<InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersRepository>();
        auto sub_factory = container->resolve<InMemoryBus::Subscribtions::Subscribers::Factories::ISubscriberInformationEntityFactory>();
        auto entity_factory = container->resolve<InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersEntityFactory>();
        auto entity_unknown = container->resolve<InMemoryBus::Subscribtions::Subscribers::UnknownSubscriberInformationEntity>();
        auto ibus = container->resolve<InMemoryBus::IBus>();
        auto handler = container->resolve<Sauerteig::Monitors::Temperatures::TemperaturesMessageHandler>();

        if (mtse_vector != nullptr)
        {
            std::cout<< "mtse_vector\n";
        }
        if (msg_repo != nullptr)
        {
            std::cout<< "msg_repo\n";
        }
        if (sub_factory != nullptr)
        {
            std::cout<< "sub_factory\n";
        }
        if (entity_factory != nullptr)
        {
            std::cout<< "entity_factory\n";
        }
        if (entity_unknown != nullptr)
        {
            std::cout<< "entity_unknown\n";
        }
        if (ibus != nullptr)
        {
            std::cout<< "ibus\n";
        }
        if (handler != nullptr)
        {
            std::cout<< "handler\n";
        }

        auto notifier_pool = container->resolve<::InMemoryBus::Notifiers::INotifierThreadPool>();
        notifier_pool->initialize(4);

        auto failed_messages_processor = container->resolve<::InMemoryBus::Notifiers::Failed::IFailedMessageQueueProcessor>();
        failed_messages_processor->initialize();

        ITemperaturesPublisher_SPtr temperatures_publisher = container->resolve<Sauerteig::Interfaces::Publishers::ITemperaturesPublisher>();
        std::thread temperatures_publisher_thread { std::thread([temperatures_publisher]() {(*temperatures_publisher)();}) };

        ITemperaturesMessageHandler_SPtr temperatures_message_handler = container->resolve<Sauerteig::Interfaces::Monitors::Temperatures::ITemperaturesMessageHandler>();
        std::thread temperatures_message_handler_thread { std::thread([temperatures_message_handler]() {(*temperatures_message_handler)();}) };

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
