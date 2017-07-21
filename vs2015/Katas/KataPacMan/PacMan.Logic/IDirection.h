#pragma once

#include <memory>
#include "Heading.h"

namespace PacMan
{
    namespace Logic
    {
        class IDirection
        {
        public:
            virtual ~IDirection () = default;

            virtual Heading get_heading () const = 0;
            virtual void set_heading ( Heading heading ) = 0;
        };

        typedef std::shared_ptr<IDirection> IDirection_Ptr;
    };
};
