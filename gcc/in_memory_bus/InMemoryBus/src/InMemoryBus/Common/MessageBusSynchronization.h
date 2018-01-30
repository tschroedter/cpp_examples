/*
 * MessageBusSynchronization.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_COMMON_MESSAGEBUSSYNCHRONIZATION_H_
#define SRC_INMEMORYBUS_COMMON_MESSAGEBUSSYNCHRONIZATION_H_

#include <memory>
#include <mutex>
#include <atomic>
#include <condition_variable>

using namespace std;

namespace InMemoryBus {
namespace Common {

class MessageBusSynchronization {
 public:
  MessageBusSynchronization() = default;
  virtual ~MessageBusSynchronization() = default;

  atomic_bool is_stop_requested_failed_messages_processor { false };
  bool is_messages_avalable_failed_messages_processor = false;
  mutex mutex_failed_messages_processor;
  condition_variable messages_available_failed_messages_processor;

  atomic_bool is_stop_requested_for_thread_pool { false };
  bool is_messages_avalable_for_thread_pool = false;
  mutex mutex_thread_pool;
  condition_variable messages_available;
};

}
}

typedef shared_ptr<InMemoryBus::Common::MessageBusSynchronization> MessageBusSynchronization_SPtr;

#endif /* SRC_INMEMORYBUS_COMMON_MESSAGEBUSSYNCHRONIZATION_H_ */
