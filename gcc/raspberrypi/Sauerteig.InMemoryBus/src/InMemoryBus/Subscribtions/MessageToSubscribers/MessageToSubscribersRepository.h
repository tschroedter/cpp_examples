/*
 * MessageToSubscribersRepository.h
 *
 *  Created on: 30 Oct. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSREPOSITORY_H_
#define SRC_INMEMORYBUS_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSREPOSITORY_H_

#include "IMessageToSubscribersRepository.h"
#include "../../Common/BaseRepository.h"
#include "IMessageToSubscribersEntity.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {
class MessageToSubscribersRepository : public IMessageToSubscribersRepository {
 public:
  MessageToSubscribersRepository(IMessageToSubscribersEntityVector_SPtr subscribers);
  virtual ~MessageToSubscribersRepository() = default;

  IMessageToSubscribersEntityVector_SPtr get_all_subscribers() const override;
  IMessageToSubscribersEntity_SPtr find_subscriber_by_message_type(const string& message_type) override;
  void remove(const IMessageToSubscribersEntity_SPtr information) override;
  void add(const IMessageToSubscribersEntity_SPtr information) override;
  size_t size() const override;

 private:
  shared_ptr<InMemoryBus::Common::BaseRepository<IMessageToSubscribersEntity>> m_subscribers;
  IMessageToSubscribersEntity_SPtr m_unknown;
};
}
}
}

typedef shared_ptr<InMemoryBus::Subscribtions::MessageToSubscribers::MessageToSubscribersRepository> MessageToSubscribersRepository_SPtr;

#endif /* SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSREPOSITORY_H_ */
