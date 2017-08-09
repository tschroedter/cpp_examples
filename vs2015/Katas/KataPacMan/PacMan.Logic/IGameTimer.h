#pragma once

#include <memory>
#include "IPlayingField.h"
#include "IObjectsMover.h"

namespace PacMan
{
    namespace Logic
    {
        class IGameTimer
        {
        public:
            virtual ~IGameTimer () = default;

            virtual void initialize ( const IPlayingField_Ptr playing_field ) = 0;
            virtual void tick () = 0;
            virtual virtual ValidationStatus get_status () const = 0;
        };

        typedef std::shared_ptr<IGameTimer> IGameTimer_Ptr;
    };
};
