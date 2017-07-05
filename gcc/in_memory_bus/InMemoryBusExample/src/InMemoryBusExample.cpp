//============================================================================
// Name        : InMemoryBusExample.cpp
// Author      : Thomas Schroedter
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include "subscribers/SubscriberInformation.h"
#include "subscribers/SubscriberInformationRepository.h"
#include "MessageBus.h"
#include "ComponentA.h"
#include "ComponentB.h"

using namespace std;

InMemoryBus::SubscriberFunction DOES_NOT_MATTER = 0;

int main()
{
    cout << "InMemoryBusExample" << endl;

    InMemoryBus::Subscribers subscribers;
    InMemoryBus::Messages messages;
    InMemoryBus::MessageBus messageBus
    { &subscribers, &messages };
    InMemoryBusExample::ComponentA compA
    { &messageBus };
    InMemoryBusExample::ComponentB compB
    { &messageBus };

    // This is supposed to act like a game loop.
    for (int ctr = 0; ctr < 50; ctr++)
    {
        compA.update();
        compB.update();
        messageBus.notify();
    }

    // Memory leak test
    auto sp_vector = std::make_shared<InMemoryBus::SubscriberInformationVector>();
    InMemoryBus::SubscriberInformationRepository repo{sp_vector};

    for (int i =0; i <1000000; i++)
    {
        std::string id = std::to_string(i);

        auto info = std::make_shared<InMemoryBus::SubscriberInformation>(id, DOES_NOT_MATTER);

        repo.add(info);

        std::cout << "Added " << id << " to repository...\n";

        repo.remove(info);

        std::cout << "...removed " << id << " from repository!\n";
    }

    return 0;
}
