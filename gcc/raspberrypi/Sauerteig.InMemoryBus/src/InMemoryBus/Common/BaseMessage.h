/*
 * BaseMessage.h
 *
 *  Created on: 23Jun.,2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_COMMON_BASEMESSAGE_H_
#define INMEMORYBUS_COMMON_BASEMESSAGE_H_

#include <string>
#include <memory>

namespace InMemoryBus {
namespace Common {

using namespace std;

class BaseMessage {
 private:
  string m_messageType;

 public:
  BaseMessage(const string messageType);
  virtual ~BaseMessage() = default;
  virtual string getType() const;
};

}
}

typedef std::shared_ptr<InMemoryBus::Common::BaseMessage> BaseMessage_SPtr;

#endif /* INMEMORYBUS_COMMON_BASEMESSAGE_H_ */
