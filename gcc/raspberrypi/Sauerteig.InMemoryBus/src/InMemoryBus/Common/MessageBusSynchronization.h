/*
 * MessageBusSynchronization.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_COMMON_MESSAGEBUSSYNCHRONIZATION_H_
#define INMEMORYBUS_COMMON_MESSAGEBUSSYNCHRONIZATION_H_

#include <memory>
#include <mutex>
#include <atomic>
#include <condition_variable>

namespace InMemoryBus {
namespace Common {

class MessageBusSynchronization {
 public:
  MessageBusSynchronization() = default;
  virtual ~MessageBusSynchronization() = default;

  std::atomic_bool is_stop_requested_failed_messages_processor { false };
  bool is_messages_avalable_failed_messages_processor = false;
  std::mutex mutex_failed_messages_processor;
  std::condition_variable messages_available_failed_messages_processor;

  std::atomic_bool is_stop_requested_for_thread_pool { false };
  bool is_messages_avalable_for_thread_pool = false;
  std::mutex mutex;
  std::condition_variable messages_available;
};

}
}

typedef std::shared_ptr<InMemoryBus::Common::MessageBusSynchronization> MessageBusSynchronization_SPtr;

#endif /* INMEMORYBUS_COMMON_MESSAGEBUSSYNCHRONIZATION_H_ */
