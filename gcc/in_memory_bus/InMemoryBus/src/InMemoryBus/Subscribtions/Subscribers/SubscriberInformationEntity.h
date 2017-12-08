/*
 * SubscriberInformation.h
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONENTITY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONENTITY_H_

#include <memory>
#include <string>
#include <vector>
#include <mutex>
#include "../../BaseEntity.h"
#include "../../Typedefs.h"
#include "ISubscriberInformationEntity.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
class SubscriberInformationEntity : public ISubscriberInformationEntity {
 public:
  SubscriberInformationEntity(const string id, const string message_type, const SubscriberFunction function);
  virtual ~SubscriberInformationEntity() = default;

  friend bool operator<(const SubscriberInformationEntity& one, const SubscriberInformationEntity& two);

  string get_subscriber_id() const override;
  string get_message_type() const override;
  SubscriberFunction get_subscriber_function() const override;
  bool try_lock() override;
  void unlock() override;

 private:
  string m_subscriber_id;
  string m_message_type;
  SubscriberFunction m_subscriber_function = nullptr;
  mutex m_mutex;
};
}
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONENTITY_H_ */
