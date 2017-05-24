#pragma once

#include <memory>

namespace PacMan
{
    namespace Logic
    {
        class ILocation
        {
        public:
            virtual ~ILocation () = default;

            virtual size_t get_row () const = 0;
            virtual size_t get_column () const = 0;
        };

        typedef std::shared_ptr<ILocation> ILocation_Ptr;
    };
};
