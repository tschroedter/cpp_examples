#pragma once
#include <memory>
#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        class IObjectMover
        {
        public:
            virtual ~IObjectMover () = default;

            virtual void move_object (
                const Row from_row,
                const Column from_columns ) = 0;
            virtual void initialize ( const IPlayingField_Ptr& playing_field ) = 0;
        };

        typedef std::shared_ptr<IObjectMover> IObjectMover_Ptr;
    };
};
