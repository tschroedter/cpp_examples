//============================================================================
// Name        : InMemoryBusExample.cpp
// Author      : Thomas Schroedter
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <string.h>
#include "MessageBus.h"
#include "ComponentA.h"
#include "ComponentB.h"
#include "ComponentOtherA.h"
#include "ComponentOther.h"
#include "exceptions/ArgumentInvalidException.h"

using namespace std;

InMemoryBus::SubscriberFunction DOES_NOT_MATTER = 0;

int main()
{
    try
    {
        cout << "InMemoryBusExample" << endl;

        InMemoryBus::SubscriberInformationVector_SPtr informations =
                std::make_shared<InMemoryBus::SubscriberInformationVector>();

        InMemoryBus::SubscriberInformationRepository_SPtr subscribers =
                std::make_shared<InMemoryBus::SubscriberInformationRepository>(
                        informations);

        InMemoryBus::Messages messages;
        InMemoryBus::MessageBus messageBus
        { subscribers, &messages };
        InMemoryBusExample::ComponentA compA
        { &messageBus };
        InMemoryBusExample::ComponentB compB
        { &messageBus };
        InMemoryBusExample::ComponentOtherA otherA
        { &messageBus };
        InMemoryBusExample::ComponentOther otherB
        { &messageBus };

        // This is supposed to act like a game loop.
        //for (int ctr = 0; ctr < 5; ctr++)
        //{
        compA.update();
        compB.update();
        otherA.update();
        otherB.update();
        messageBus.notify();
        //}

        // Memory leak test
        auto sp_vector = std::make_shared<
                InMemoryBus::SubscriberInformationVector>();
        InMemoryBus::SubscriberInformationRepository repo
        { sp_vector };

        for (int i = 0; i < 10; i++)
        {
            std::string id = std::to_string(i);

            auto info = std::make_shared<InMemoryBus::SubscriberInformation>(id,
                    "type", DOES_NOT_MATTER);

            repo.add(info);

            std::cout << "Added " << id << " to repository...\n";

            repo.remove(info);

            std::cout << "...removed " << id << " from repository!\n";
        }
    } catch (InMemoryBus::ArgumentInvalidException const & ex)
    {
        std::cout << "Exception: " << ex.get_message();
    }

    return (0);
}
