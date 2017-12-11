/*
 * TestBaseEntity.h
 *
 *  Created on: 24 Aug. 2017
 *      Author: tom
 */

#ifndef TESTBASEENTITY_H_
#define TESTBASEENTITY_H_

#include "InMemoryBus/Common/BaseEntity.h"

namespace InMemoryBusTests {

class TestBaseEntity : public InMemoryBus::Common::BaseEntity {
 public:
  TestBaseEntity();
  TestBaseEntity(std::string uuid_as_text);
  virtual ~TestBaseEntity();
};

}

#endif /* TESTBASEENTITY_H_ */
