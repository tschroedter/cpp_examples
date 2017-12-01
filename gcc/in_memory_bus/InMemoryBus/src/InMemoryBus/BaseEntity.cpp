/*
 * BaseEntity.cpp
 *
 *  Created on: 23 Aug. 2017
 *      Author: tom
 */

#include "BaseEntity.h"
#include "uuid/uuid.h"
#include <memory>
#include <string>
#include <iostream>
#include "uuid/uuid.h"

namespace InMemoryBus {

BaseEntity::BaseEntity() {
  uuid_generate(m_id);
}

BaseEntity::BaseEntity(const std::string& uuid_as_text) {
  int result = uuid_parse(uuid_as_text.c_str(), m_id);

  if (result != 0) {
    std::cout << "Result is " << result << " for text '" << uuid_as_text << "'!\n";  // todo error result = 0 ==> OKAY, throw exception
    exit(result);
  }
}

void BaseEntity::get_id(uuid_t& other) const {
  uuid_copy(other, m_id);
}

bool BaseEntity::is_id_equal_to(uuid_t other) const {
  return (uuid_compare(m_id, other) == 0);
}
} /* namespace InMemoryBus */
