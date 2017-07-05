/*
 * IBus.h
 *
 *  Created on: 14Jun.,2017
 *      Author: tom
 */

#ifndef IBUS_H_
#define IBUS_H_

#include <functional>
#include "BaseMessage.h"
#include "Typedefs.h"

namespace InMemoryBus {

class IBus {
public:
	virtual ~IBus() = default;
    virtual void subscribe(std::string subscriber_id, SubscriberFunction messageReceiver) = 0;
    virtual void unsubscribe(std::string subscriber_id) = 0;
	virtual void publish(BaseMessage* p_message) = 0;
	virtual void notify() = 0;
};

} /* namespace InMemoryBus */

#endif /* IBUS_H_ */
