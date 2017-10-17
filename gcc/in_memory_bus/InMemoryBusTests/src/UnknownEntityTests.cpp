/*
 * UnknownEntity.Tests.cpp
 *
 *  Created on: 24 Aug. 2017
 *      Author: tom
 */

/*
 * MessageBusTests.cpp
 *
 *  Created on: 13Jun.,2017
 *      Author: tom
 */

#include <iostream>
#include <gtest/gtest.h>
#include "UnknownEntity.h"
#include "uuid/uuid.h"

namespace InMemoryBusTests
{
    void uuid_pointer_to_uuid(const unsigned char* p_array, uuid_t& result)
    {
        for (int i = 0; i < 16; i++)
        {
            result[i] = p_array[i];
        }
    }

    TEST(UnknownEntity, get_id_returns_id)
    {
        // Arrange
        using namespace InMemoryBus;

        uuid_t expected;
        uuid_parse("00000000-0000-0000-0000-000000000000", expected);

        UnknownEntity sut
        { };

        // Act
        // Assert
        bool pass = sut.is_id_equal_to(expected);

        EXPECT_EQ(true, pass);
    }
}
;
