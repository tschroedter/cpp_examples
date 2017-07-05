/*
 * BusNode.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include <functional>
#include <algorithm>
#include <iostream>
#include "BusNode.h"
#include "MessageBus.h"
#include "BaseMessage.h"

namespace InMemoryBus
{

    BusNode::BusNode(std::string subscriber_id, MessageBus *messageBus)
    {
        this->messageBus = messageBus;
        this->messageBus->subscribe(subscriber_id, this->getNotifyFunc());
    }

    BusNode::~BusNode()
    {
    }

    void BusNode::update()
    {
    }

    std::function<void(BaseMessage*)> BusNode::getNotifyFunc()
    {
        auto messageListener = [=](BaseMessage* p_message) -> void
        {
            this->onNotify(p_message);
        };
        return messageListener;
    }

    void BusNode::send(BaseMessage* p_message)
    {
        messageBus->publish(p_message);
    }

    void BusNode::onNotify(BaseMessage* message)
    {
    }

} /* namespace InMemoryBus */
