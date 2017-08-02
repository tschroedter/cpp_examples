#pragma once

#include <memory>
#include "IPlayingField.h"
#include "IObjectMover.h"
#include "IObjectsMover.h"

namespace PacMan
{
    namespace Logic
    {
        class IGameTimer
        {
        public:
            virtual ~IGameTimer () = default;

            virtual void initialize ( const IPlayingField_Ptr playing_field,
                                      const IObjectMover_Ptr object_mover,
                                      const IObjectsMover_Ptr objects_mover ) = 0;
            virtual void tick () = 0;
            virtual virtual ValidationStatus get_status() const = 0;
        };

        typedef std::shared_ptr<IGameTimer> IGameTimer_Ptr;
    };
};
