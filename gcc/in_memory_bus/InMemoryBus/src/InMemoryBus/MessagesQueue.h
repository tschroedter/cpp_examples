/*
 * NewMessagesQueue.h
 *
 *  Created on: 28 Nov. 2017
 *      Author: tom
 */

#ifndef NEWMESSAGESQUEUE_H_
#define NEWMESSAGESQUEUE_H_

#include <queue>
#include "BaseMessage.h"
#include "IMessagesQueue.h"

namespace InMemoryBus {

class MessagesQueue : public IMessagesQueue {
 public:
  MessagesQueue() = default;
  virtual ~MessagesQueue() = default;

  BaseMessage* front() override;
  void pop() override;
  void push(BaseMessage* message) override;
  size_t size() const override;

 private:
  std::queue<BaseMessage*> m_queue { };
};

} /* namespace InMemoryBus */

#endif /* NEWMESSAGESQUEUE_H_ */
