/*
 * BaseMessage.h
 *
 *  Created on: 23Jun.,2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_COMMON_BASEMESSAGE_H_
#define SRC_INMEMORYBUS_COMMON_BASEMESSAGE_H_

#include <string>
#include <memory>
#include <atomic>

typedef ulong MessageIdType;

namespace InMemoryBus {
namespace Common {

using namespace std;

class BaseMessage {
 private:
  string m_messageType;

 public:
  BaseMessage(const string messageType);
  virtual ~BaseMessage() = default;
  virtual string getType() const;   // todo rename to get_type
  virtual MessageIdType get_id() const;
  virtual void create_new_id();

 protected:
  MessageIdType m_id = 0;
  static atomic_ulong next_id;
};

}
}

typedef std::shared_ptr<InMemoryBus::Common::BaseMessage> BaseMessage_SPtr;

#endif /* SRC_INMEMORYBUS_COMMON_BASEMESSAGE_H_ */
