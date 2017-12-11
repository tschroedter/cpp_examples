/*
 * TestBaseEntity.cpp
 *
 *  Created on: 24 Aug. 2017
 *      Author: tom
 */

#include "TestBaseEntity.h"

namespace InMemoryBusTests {

TestBaseEntity::TestBaseEntity() {
}

TestBaseEntity::TestBaseEntity(std::string uuid_as_text)
    : BaseEntity(uuid_as_text) {
}

TestBaseEntity::~TestBaseEntity() {
}

}
