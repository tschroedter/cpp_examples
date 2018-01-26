/*
 * BaseRepository.h
 *
 *  Created on: 22 Aug. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_COMMON_UNKNOWNENTITY_H_
#define SRC_INMEMORYBUS_COMMON_UNKNOWNENTITY_H_

#include "BaseEntity.h"
#include "uuid/uuid.h"

namespace InMemoryBus {
namespace Common {
class UnknownEntity : public BaseEntity {
 public:
  UnknownEntity();
  virtual ~UnknownEntity();
};
}
}

#endif /* SRC_INMEMORYBUS_COMMON_UNKNOWNENTITY_H_ */
