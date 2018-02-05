/*
 * IMessageBusNodeFactory.h
 *
 *  Created on: 31 Jan. 2018
 *      Author: tom
 */

#ifndef SRC_INTERFACES_FACTORIES_IMESSAGEBUSNODEFACTORY_H_
#define SRC_INTERFACES_FACTORIES_IMESSAGEBUSNODEFACTORY_H_

#include <memory>
#include <assert.h>
#include <string>

using namespace std;

namespace Sauerteig {
namespace Interfaces {
namespace Factories {

template <class T>
class IMessageBusNodeFactory {
 public:
    virtual ~IMessageBusNodeFactory() = default;

    virtual shared_ptr<T> create(string subscriber_id) = 0;
    virtual void release(shared_ptr<T> bus_node) = 0;
    };

}
}
}

template<typename T>
using IMessageBusNodeFactory_SPtr = std::shared_ptr<Sauerteig::Interfaces::Factories::IMessageBusNodeFactory<T>>;

// todo typedef shared_ptr<Sauerteig::Interfaces::Factories::IMessageBusNodeFactory> IMessageBusNodeFactory_SPtr;

#endif /* SRC_INTERFACES_FACTORIES_IMESSAGEBUSNODEFACTORY_H_ */
