/*
 * MessageBus.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef MESSAGEBUS_H_
#define MESSAGEBUS_H_

#include <functional>
#include <queue>
#include <vector>
#include <map>
#include "IBus.h"
#include "subscribers/SubscriberInformation.h"
#include "Typedefs.h"

namespace InMemoryBus {

typedef std::map<std::string, Subscribers*> MessagesToSubscribers;

class MessageBus: public IBus {
public:
	MessageBus(Subscribers* subscribers, Messages* messages);
	virtual ~MessageBus();
	void subscribe(std::string subscriber_id, SubscriberFunction messageReceiver);
	void unsubscribe(std::string subscriber_id);
	void publish(BaseMessage* p_message);
	void notify();

private:
	Subscribers* m_subsribers;
	Messages* m_messages;
	MessagesToSubscribers m_messages_to_subscribers;
};

} /* namespace InMemoryBus */

#endif /* MESSAGEBUS_H_ */
