#pragma once

#include <memory>
#include "IPlayingField.h"
#include "IMovingObjectsRepository.h"

namespace PacMan
{
    namespace Logic
    {
        class IObjectsMoveExecuter
        {
        public:
            virtual ~IObjectsMoveExecuter () = default;

            virtual void initialize (
                const IPlayingField_Ptr playing_field,
                const IMovingObjectsRepository_Ptr repository ) = 0;
            virtual void move_objects () const = 0;
        };

        typedef std::shared_ptr<IObjectsMoveExecuter> IObjectsMoveExecuter_Ptr;
    };
};
