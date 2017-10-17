/*
 * BaseEntityTests.cpp
 *
 *  Created on: 24 Aug. 2017
 *      Author: tom
 */

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
#include "TestBaseEntity.h"
#include "uuid/uuid.h"

namespace InMemoryBusTests
{
    TEST(BaseEntity, get_id_returns_id)
    {
        // Arrange
        using namespace InMemoryBus;

        uuid_t expected;
        uuid_parse("00000000-0000-0000-0000-000000000000", expected);

        // Act
        TestBaseEntity sut
        { };

        // Assert
        bool actual = sut.is_id_equal_to(expected);

        EXPECT_EQ(false, actual);
    }

    TEST(BaseEntity, constructor_creates_different_ids)
    {
        // Arrange
        using namespace InMemoryBus;

        // Act
        TestBaseEntity sut_one
        { };
        TestBaseEntity sut_two
        { };
        uuid_t two;
        sut_two.get_id(two);

        // Assert
        bool actual = sut_one.is_id_equal_to(two);

        EXPECT_EQ(false, actual);
    }

    TEST(BaseEntity, is_id_equal_to_returns_false_for_different_ids)
    {
        // Arrange
        using namespace InMemoryBus;

        uuid_t other_id;
        uuid_parse("10000000-0000-0000-0000-000000000000", other_id);

        TestBaseEntity sut
        { };

        // Act
        bool actual = sut.is_id_equal_to(other_id);

        // Assert
        EXPECT_EQ(false, actual);
    }

    TEST(BaseEntity, is_id_equal_to_returns_true_for_same_id)
    {
        // Arrange
        using namespace InMemoryBus;

        TestBaseEntity sut
        { };

        uuid_t id;
        sut.get_id(id);

        // Act
        bool actual = sut.is_id_equal_to(id);

        // Assert
        EXPECT_EQ(true, actual);
    }
}
;

