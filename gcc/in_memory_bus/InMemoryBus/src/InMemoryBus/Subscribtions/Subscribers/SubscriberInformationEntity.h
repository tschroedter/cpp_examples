/*
 * SubscriberInformation.h
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONENTITY_H_
#define SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONENTITY_H_

#include <memory>
#include <string>
#include <vector>
#include <mutex>
#include "ISubscriberInformationEntity.h"
#include "../../Common/BaseEntity.h"
#include "../../Common/SubscriberFunction.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {

using namespace std;

class SubscriberInformationEntity : public ISubscriberInformationEntity {
 public:
  SubscriberInformationEntity();
  SubscriberInformationEntity(const string subscriber_id);
  SubscriberInformationEntity(const string subscriber_id, const string message_type);
  SubscriberInformationEntity(const string subscriber_id, const string message_type,
                              const InMemoryBus::Common::SubscriberFunction subscriber_function);
  virtual ~SubscriberInformationEntity() = default;

  friend bool operator<(const SubscriberInformationEntity& one, const SubscriberInformationEntity& two);

  string get_subscriber_id() const override;
  string get_message_type() const override;
  InMemoryBus::Common::SubscriberFunction get_subscriber_function() const override;
  bool try_lock() override;
  void unlock() override;

 private:
  string m_subscriber_id;
  string m_message_type;
  InMemoryBus::Common::SubscriberFunction m_subscriber_function = nullptr;
  mutex m_mutex;
};

}
}
}

#endif /* SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONENTITY_H_ */
