#pragma once

#include <memory>
#include "Heading.h"
#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        class IObjectMoveCalculator
        {
        public:
            virtual ~IObjectMoveCalculator () = default;

            virtual void calculate ( const size_t from_row,
                                     const size_t from_column,
                                     const Heading heading ) = 0;

            virtual void initialize ( const IPlayingField_Ptr& playing_field ) = 0;

            Row to_row = 0;
            Column to_column = 0;
        };

        typedef std::shared_ptr<IObjectMoveCalculator> IObjectMoveCalculator_Ptr;
    };
};
