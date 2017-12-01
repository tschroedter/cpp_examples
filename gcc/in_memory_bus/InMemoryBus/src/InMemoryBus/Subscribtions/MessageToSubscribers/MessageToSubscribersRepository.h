/*
 * MessageToSubscribersRepository.h
 *
 *  Created on: 30 Oct. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSREPOSITORY_H_
#define INMEMORYBUS_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSREPOSITORY_H_

#include "IMessageToSubscribersRepository.h"
#include "../../BaseRepository.h"
#include "IMessageToSubscribersEntity.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {
class MessageToSubscribersRepository : public IMessageToSubscribersRepository {
 public:
  MessageToSubscribersRepository(IMessageToSubscribersEntityVector_SPtr subscribers);
  virtual ~MessageToSubscribersRepository() = default;

  IMessageToSubscribersEntityVector_SPtr get_all_subscribers() const override;
  IMessageToSubscribersEntity_SPtr find_subscriber_by_message_type(const std::string& message_type) override;
  void remove(const IMessageToSubscribersEntity_SPtr information) override;
  void add(const IMessageToSubscribersEntity_SPtr information) override;
  size_t size() const override;

 private:
  std::shared_ptr<BaseRepository<IMessageToSubscribersEntity>> m_subscribers;
  IMessageToSubscribersEntity_SPtr m_unknown;
};
}
}
}

typedef std::shared_ptr<InMemoryBus::Subscribtions::MessageToSubscribers::MessageToSubscribersRepository> MessageToSubscribersRepository_SPtr;

#endif /* INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSREPOSITORY_H_ */
