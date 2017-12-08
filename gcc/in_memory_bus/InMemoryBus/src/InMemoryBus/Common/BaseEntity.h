/*
 * BaseEntity.h
 *
 *  Created on: 23 Aug. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_COMMON_BASEENTITY_H_
#define INMEMORYBUS_COMMON_BASEENTITY_H_

#include "uuid/uuid.h"
#include <memory>
#include <string>

namespace InMemoryBus {
namespace Common {

class BaseEntity {
 public:
  BaseEntity();
  BaseEntity(const std::string& uuid_as_text);
  virtual ~BaseEntity() = default;

  void get_id(uuid_t& id) const;
  bool is_id_equal_to(uuid_t other) const;

 protected:
  uuid_t m_id;
};

}
}

#endif /* INMEMORYBUS_COMMON_BASEENTITY_H_ */
