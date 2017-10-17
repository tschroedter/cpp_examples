/*
 * BaseRepository.h
 *
 *  Created on: 22 Aug. 2017
 *      Author: tom
 */

#ifndef UNKNOWNENTITY_H_
#define UNKNOWNENTITY_H_

#include "BaseEntity.h"
#include "uuid/uuid.h"

namespace InMemoryBus
{
    class UnknownEntity: public BaseEntity
    {
        public:
            UnknownEntity();
            virtual ~UnknownEntity();
    };
} /* namespace InMemoryBus */

#endif /* UNKNOWNENTITY_H_ */
