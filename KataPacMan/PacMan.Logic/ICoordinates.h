#pragma once

#include "Position.h"

namespace PacMan
{
    namespace Logic
    {
        class ICoordinates
        {
        public:
            virtual ~ICoordinates () = default;

            virtual Position get_row () = 0;
            virtual Position get_column () = 0;
        };

        typedef ICoordinates* ICoordinates_Ptr;
    };
};
