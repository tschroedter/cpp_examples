#pragma once

#include "Heading.h"
#include <memory>

namespace PacMan
{
    namespace Logic
    {
        class IInputPacManMove
        {
        public:
            virtual ~IInputPacManMove () = default;

            virtual void initialize () = 0;
            virtual Heading get_heading () const = 0;
        };

        typedef std::shared_ptr<IInputPacManMove> IInputPacManMove_Ptr;
    };
};
