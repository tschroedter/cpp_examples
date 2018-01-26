/*
 * NotifierThreadPool.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORY_NOTIFIERS_NOTIFIERTHREADPOOL_H_
#define SRC_INMEMORY_NOTIFIERS_NOTIFIERTHREADPOOL_H_

#include <thread>
#include <vector>
#include "Common/Interfaces/ILogger.h"
#include "INotifierThreadPool.h"
#include "Factories/IMessageBusNotifierFactory.h"
#include "../Common/MessageBusSynchronization.h"
#include "../Publishers/IMessageBusPublisher.h"

using namespace std;

namespace InMemoryBus {
namespace Notifiers {

#define DEFAULT_NUMBER_OF_THREADS 10

class NotifierThreadPool : public INotifierThreadPool {
 public:
  NotifierThreadPool(ILogger_SPtr logger,
                     MessageBusSynchronization_SPtr synchronization,
                     IMessageBusPublisher_SPtr publisher, IMessageBusNotifierFactory_SPtr factory);
  virtual ~NotifierThreadPool() = default;

  void initialize(int number_of_threads) override;
  void stop() override;

 private:
  ILogger_SPtr m_logger = nullptr;
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IMessageBusPublisher_SPtr m_publisher = nullptr;
  IMessageBusNotifierFactory_SPtr m_factory = nullptr;

  int m_number_of_threads = DEFAULT_NUMBER_OF_THREADS;
  vector<thread> m_threads { };

  void join_threads();
  void create_threads();
  void do_join_thread(thread& thread);
};
}
}

#endif /* SRC_INMEMORY_NOTIFIERS_NOTIFIERTHREADPOOL_H_ */
