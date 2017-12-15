/*
 * NotifierThreadPool.cpp
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#include <memory>
#include <algorithm>
#include <string>
#include "NotifierThreadPool.h"
#include "MessageBusNotifier.h"
#include "ISubscibersNotifier.h"
#include "IMessageBusNotifierFactory.h"
#include "../Exceptions/ArgumentInvalidException.h"
#include "../Common/SubscriberFunction.h"
#include "../Common/IMessagesQueue.h"
#include "../Common/MessageBusSynchronization.h"
#include "../Common/ILogger.h"
#include "../Common/General.h"
#include "../Common/BaseMessage.h"
#include "../Subscribtions/Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"
#include "../Publishers/IMessageBusPublisher.h"

namespace InMemoryBus {
namespace Notifiers {
NotifierThreadPool::NotifierThreadPool(ILogger_SPtr logger, MessageBusSynchronization_SPtr synchronization,
                                       IMessageBusPublisher_SPtr publisher,
                                       IMessageBusNotifierFactory_SPtr factory)
    : m_logger(logger),
      m_synchronization(synchronization),
      m_publisher(publisher),
      m_factory(factory) {
  if (m_logger == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create NotifierThreadPool because 'logger' is null!", "logger");
  }

  if (m_synchronization == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create NotifierThreadPool because 'synchronization' is null!",
                                               "synchronization");
  }

  if (m_publisher == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create NotifierThreadPool because 'publisher' is null!",
                                               "publisher");
  }

  if (m_factory == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create NotifierThreadPool because 'factory' is null!",
                                               "factory");
  }

  m_logger->set_prefix("NotifierThreadPool");
}

void NotifierThreadPool::initialize(int number_of_threads) {
  m_number_of_threads = number_of_threads;  // TODO Move thread creation/control behind interface for testing

  if (m_threads.size() > 0) {
    stop();
  }

  create_threads();
}

void NotifierThreadPool::create_threads() {
  m_synchronization->is_stop_requested_for_thread_pool.store(false);

  m_threads.clear();

  for (int i = 0; i < m_number_of_threads; i++) {
    IMessageBusNotifier_SPtr notifier = m_factory->create();

    m_threads.push_back(std::thread([notifier]() {(*notifier)();}));

    std::string id = InMemoryBus::Common::thread_id_to_string(m_threads[i].get_id());

    m_logger->info(std::string("Pool thread " + id + " created!"));
  }
}

void NotifierThreadPool::do_join_thread(std::thread& thread) {
  std::string id = InMemoryBus::Common::thread_id_to_string(thread.get_id());

  m_logger->info(std::string("Trying to join with pool thread " + id + " ..."));

  thread.join();

  m_logger->info(std::string("... pool thread " + id + " joined!"));
}

void NotifierThreadPool::join_threads() {
  m_synchronization->is_stop_requested_for_thread_pool.store(true);

  for (size_t i = 0; i < m_threads.size(); i++) {
    // sending dummy messages to make sure threads are stopping
    // TODO BOOST.DI Factory not working yet
    auto dummy = std::make_shared<InMemoryBus::Common::BaseMessage>("Dummy");
    m_publisher->publish(dummy);
  }

  auto join_thread = std::bind(&NotifierThreadPool::do_join_thread, this, std::placeholders::_1);

  std::for_each(m_threads.begin(), m_threads.end(), join_thread);
}

void NotifierThreadPool::stop() {
  join_threads();

  m_threads.clear();
}
}
}
