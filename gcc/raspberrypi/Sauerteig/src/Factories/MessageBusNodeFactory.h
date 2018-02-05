/*
 * MessageBusNodeFactory.h
 *
 *  Created on: 31 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_FACTORIES_MESSAGEBUSNODEFACTORY_H_
#define SRC_FACTORIES_MESSAGEBUSNODEFACTORY_H_

#include <memory>
#include <string>
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "Common/Interfaces/ILogger.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "../Interfaces/Factories/IMessageBusNodeFactory.h"

using namespace std;
using namespace Common::Exceptions;
using namespace InMemoryBus::Common;
using namespace Sauerteig::Interfaces::Factories;

namespace Sauerteig {
namespace Factories {

template<class T>
class MessageBusNodeFactory : public IMessageBusNodeFactory<T> {
 public:
    MessageBusNodeFactory(ILogger_SPtr logger, IBus_SPtr bus)
            : m_logger(logger),
              m_bus(bus) {
        static_assert(std::is_base_of<BusNode, T>::value, "T must be a descendant of BusNode");

        if (m_logger == nullptr) {
            throw ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'logger' is null!",
                                           "logger");
        }

        if (m_bus == nullptr) {
            throw ArgumentInvalidException("Can't create TemperaturesMessageHandler because 'bus' is null!", "bus");
        }
    }

    virtual ~MessageBusNodeFactory() {
    }
    ;

    virtual shared_ptr<T> create(string subscriber_id) override {
        auto instance = make_shared<T>(m_logger, m_bus, subscriber_id);

        return instance;
    }

    virtual void release(shared_ptr<T> bus_node) override {
    }

    /*
    template<typename Arg, typename ... Args>   // todo can't make this virtual otherwise would be great
    shared_ptr<T> create(Arg subscriber_id, Args ... args) {
        static_assert(is_base_of<string, Arg>::value, "Arg must be a descendant of std::string");

        auto instance = make_shared<T>(m_logger, m_bus, subscriber_id, args...);

        return instance;
    }
    */

 protected:
    ILogger_SPtr m_logger = nullptr;
    IBus_SPtr m_bus = nullptr;
};

}
}

template<typename T>
using MessageBusNodeFactory_SPtr = std::shared_ptr<Sauerteig::Factories::MessageBusNodeFactory<T>>;

#endif /* SRC_FACTORIES_MESSAGEBUSNODEFACTORY_H_ */
