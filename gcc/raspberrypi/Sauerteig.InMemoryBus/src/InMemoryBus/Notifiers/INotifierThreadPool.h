/*
 * INotifierThreadPool.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORY_NOTIFIERS_INOTIFIERTHREADPOOL_H_
#define INMEMORY_NOTIFIERS_INOTIFIERTHREADPOOL_H_

#include <memory>

namespace InMemoryBus {
namespace Notifiers {
class INotifierThreadPool {
 public:
  virtual ~INotifierThreadPool() = default;

  virtual void initialize(int number_of_threads) = 0;
  virtual void stop() = 0;
};
}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::INotifierThreadPool> INotifierThreadPool_SPtr;

#endif /* NOTIFIERS_INOTIFIERTHREADPOOL_H_ */
