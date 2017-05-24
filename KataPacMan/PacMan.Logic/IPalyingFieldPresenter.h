#pragma once

#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        class IPalyingFieldPresenter
        {
        public:
            virtual ~IPalyingFieldPresenter () = default;

            virtual void set_playing_field ( IPlayingField_Ptr playing_field ) = 0;
            virtual void show () = 0;
        };

        typedef IPalyingFieldPresenter* IPalyingFieldPresenter_Ptr;
    };
};
