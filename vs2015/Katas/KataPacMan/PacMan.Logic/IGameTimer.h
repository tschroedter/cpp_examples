#pragma once

#include <memory>
#include "IPlayingField.h"
#include "IObjectMover.h"

namespace PacMan
{
    namespace Logic
    {
        class IGameTimer
        {
        public:
            virtual ~IGameTimer () = default;

            virtual void initialize ( const IPlayingField_Ptr playing_field,
                                      const IObjectMover_Ptr object_mover ) = 0;
            virtual void tick () = 0;
        };

        typedef std::shared_ptr<IGameTimer> IGameTimer_Ptr;
    };
};
