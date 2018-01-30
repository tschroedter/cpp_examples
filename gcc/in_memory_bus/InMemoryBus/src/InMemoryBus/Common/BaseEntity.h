/*
 * BaseEntity.h
 *
 *  Created on: 23 Aug. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_COMMON_BASEENTITY_H_
#define SRC_INMEMORYBUS_COMMON_BASEENTITY_H_

#include <uuid/uuid.h>
#include <memory>
#include <string>

using namespace std;

namespace InMemoryBus {
namespace Common {

class BaseEntity {
 public:
  BaseEntity();
  BaseEntity(const string& uuid_as_text);
  virtual ~BaseEntity() = default;

  void get_id(uuid_t& id) const;
  bool is_id_equal_to(uuid_t other) const;

 protected:
  uuid_t m_id;
};

}
}

#endif /* SRC_INMEMORYBUS_COMMON_BASEENTITY_H_ */
