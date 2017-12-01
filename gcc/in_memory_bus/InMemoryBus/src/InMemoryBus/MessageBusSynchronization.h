/*
 * MessageBusSynchronization.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef MESSAGEBUSSYNCHRONIZATION_H_
#define MESSAGEBUSSYNCHRONIZATION_H_

#include <memory>
#include <mutex>
#include <atomic>
#include <condition_variable>

namespace InMemoryBus {

class MessageBusSynchronization {
 public:
  MessageBusSynchronization() = default;
  virtual ~MessageBusSynchronization() = default;

  std::atomic_bool is_stop_requested { false };
  bool is_messages_avalable = false;
  std::mutex mutex;
  std::condition_variable messages_available;
};

} /* namespace InMemoryBus */

typedef std::shared_ptr<InMemoryBus::MessageBusSynchronization> MessageBusSynchronization_SPtr;

#endif /* MESSAGEBUSSYNCHRONIZATION_H_ */
