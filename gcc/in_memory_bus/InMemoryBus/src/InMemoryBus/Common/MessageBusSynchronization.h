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

  std::atomic_bool is_stop_requested { false };
  bool is_messages_avalable = false;
  std::mutex mutex;
  std::condition_variable messages_available;
};

}
}

typedef std::shared_ptr<InMemoryBus::Common::MessageBusSynchronization> MessageBusSynchronization_SPtr;

#endif /* INMEMORYBUS_COMMON_MESSAGEBUSSYNCHRONIZATION_H_ */
