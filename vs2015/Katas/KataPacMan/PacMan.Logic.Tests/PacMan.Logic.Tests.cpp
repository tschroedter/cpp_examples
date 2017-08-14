#include "stdafx.h"
#include <gtest/gtest.h>

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            int main ( int ac, char* av[] )
            {
                testing::InitGoogleTest(&ac, av);
                return RUN_ALL_TESTS();
            }
        };
    };
};
