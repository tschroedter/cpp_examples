/*
 * UnknownEntity.cpp
 *
 *  Created on: 23 Aug. 2017
 *      Author: tom
 */

#include "UnknownEntity.h"
#include "BaseEntity.h"
#include "uuid/uuid.h"

namespace InMemoryBus {
UnknownEntity::UnknownEntity()
    : InMemoryBus::BaseEntity("00000000-0000-0000-0000-000000000000") {
}

UnknownEntity::~UnknownEntity() {
}
}

