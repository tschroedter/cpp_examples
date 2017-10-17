/*
 * TestBaseEntity.h
 *
 *  Created on: 24 Aug. 2017
 *      Author: tom
 */

#ifndef TESTBASEENTITY_H_
#define TESTBASEENTITY_H_

#include "BaseEntity.h"

namespace InMemoryBus
{

    class TestBaseEntity: public BaseEntity
    {
        public:
            TestBaseEntity();
            virtual ~TestBaseEntity();
    };

} /* namespace InMemoryBus */

#endif /* TESTBASEENTITY_H_ */
