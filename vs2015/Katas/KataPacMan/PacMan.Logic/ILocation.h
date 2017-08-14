#pragma once

#include <memory>
#include "RowAndColumn.h"

namespace PacMan
{
    namespace Logic
    {
        class ILocation
        {
        public:
            virtual ~ILocation () = default;

            virtual Row get_row () const = 0;
            virtual Column get_column () const = 0;
        };

        typedef std::shared_ptr<ILocation> ILocation_Ptr;
    };
};
