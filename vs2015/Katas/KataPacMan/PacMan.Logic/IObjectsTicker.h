#pragma once

#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        class IObjectsTicker
        {
        public:
            virtual ~IObjectsTicker () = default;

            virtual void initialize (
                const IPlayingField_Ptr& playing_field ) = 0;

            virtual void tick () const = 0;
        };

        typedef std::shared_ptr<IObjectsTicker> IObjectsTicker_Ptr;
    };
};
