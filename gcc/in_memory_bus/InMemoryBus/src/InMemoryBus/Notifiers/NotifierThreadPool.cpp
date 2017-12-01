/*
 * NotifierThreadPool.cpp
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#include <memory>
#include <algorithm>
#include "NotifierThreadPool.h"
#include "MessageBusNotifier.h"
#include "../Exceptions/ArgumentInvalidException.h"
#include "../Typedefs.h"
#include "../IMessagesQueue.h"
#include "../MessageBusSynchronization.h"
#include "../Subscribtions/Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

namespace InMemoryBus {
namespace Notifiers {
NotifierThreadPool::NotifierThreadPool(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages,
                                       ISubscribtionManager_SPtr manager)
    : m_synchronization(synchronization),
      m_messages(messages),
      m_manager(manager) {
  if (m_synchronization == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create NotifierThreadPool because 'm_synchronization' is null!",
                                               "m_synchronization");
  }

  if (m_messages == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create NotifierThreadPool because 'm_messages' is null!",
                                               "m_messages");
  }

  if (m_manager == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create NotifierThreadPool because 'm_manager' is null!",
                                               "m_manager");
  }
}

void NotifierThreadPool::initialize(int number_of_threads) {
  m_number_of_threads = number_of_threads;

  if (m_threads.size() > 0) {
    stop();
  }

  create_threads();
}

void NotifierThreadPool::create_threads() {
  m_synchronization->is_stop_requested.store(false);

  m_threads.clear();

  for (int i; i < m_number_of_threads; i++) {
    IMessageBusNotifier_SPtr notifier = std::make_shared<MessageBusNotifier>(m_synchronization, m_messages, m_manager);  // TODO use container to create notifiers

    m_threads.push_back(std::thread([notifier]() {(*notifier)();}));
  }
}

void NotifierThreadPool::do_join_thread(std::thread& thread) {
  thread.join();
}

void NotifierThreadPool::join_threads() {
  m_synchronization->is_stop_requested.store(true);
  m_synchronization->messages_available.notify_all();

  auto join_thread = std::bind(&NotifierThreadPool::do_join_thread, this, std::placeholders::_1);

  std::for_each(m_threads.begin(), m_threads.end(), join_thread);
}

void NotifierThreadPool::stop() {
  join_threads();

  m_threads.clear();
}
}
}
