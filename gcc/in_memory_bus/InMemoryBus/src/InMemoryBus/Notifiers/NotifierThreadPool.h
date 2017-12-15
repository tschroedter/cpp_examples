/*
 * NotifierThreadPool.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORY_NOTIFIERS_NOTIFIERTHREADPOOL_H_
#define INMEMORY_NOTIFIERS_NOTIFIERTHREADPOOL_H_

#include <thread>
#include <vector>
#include "INotifierThreadPool.h"
#include "ISubscibersNotifier.h"
#include "Factories/IMessageBusNotifierFactory.h"
#include "../Common/SubscriberFunction.h"
#include "../Common/ILogger.h"
#include "../Common/IMessagesQueue.h"
#include "../Common/MessageBusSynchronization.h"
#include "../Subscribtions/ISubscribtionManager.h"
#include "../Publishers/IMessageBusPublisher.h"

namespace InMemoryBus {
namespace Notifiers {

#define DEFAULT_NUMBER_OF_THREADS 10

class NotifierThreadPool : public INotifierThreadPool {
 public:
  NotifierThreadPool(ILogger_SPtr logger, MessageBusSynchronization_SPtr synchronization,
                     IMessageBusPublisher_SPtr publisher,
                     IMessageBusNotifierFactory_SPtr factory);
  virtual ~NotifierThreadPool() = default;

  void initialize(int number_of_threads) override;
  void stop() override;

 private:
  ILogger_SPtr m_logger = nullptr;
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IMessageBusPublisher_SPtr m_publisher = nullptr;
  IMessageBusNotifierFactory_SPtr m_factory = nullptr;

  int m_number_of_threads = DEFAULT_NUMBER_OF_THREADS;
  std::vector<std::thread> m_threads { };

  void join_threads();
  void create_threads();
  void do_join_thread(std::thread& thread);
};
}
}

#endif /* INMEMORY_NOTIFIERS_NOTIFIERTHREADPOOL_H_ */
