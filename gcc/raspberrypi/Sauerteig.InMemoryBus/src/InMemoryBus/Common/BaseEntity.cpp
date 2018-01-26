/*
 * BaseEntity.cpp
 *
 *  Created on: 23 Aug. 2017
 *      Author: tom
 */
#include "BaseEntity.h"
#include <uuid/uuid.h>
#include <memory>
#include <string>
#include <iostream>
#include "Common/Exceptions/ArgumentInvalidExceptions.h"

using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Common {

BaseEntity::BaseEntity() {
  uuid_generate(m_id);
}

BaseEntity::BaseEntity(const std::string& uuid_as_text) {

  int result = uuid_parse(uuid_as_text.c_str(), m_id);

  if (result != 0) {
    throw ArgumentInvalidException(
        "Can't create BaseEntity because 'uuid_as_text' is '" + uuid_as_text + "'!", "uuid_as_text");
  }
}

void BaseEntity::get_id(uuid_t& other) const {
  uuid_copy(other, m_id);
}

bool BaseEntity::is_id_equal_to(uuid_t other) const {
  return (uuid_compare(m_id, other) == 0);
}

}
}
