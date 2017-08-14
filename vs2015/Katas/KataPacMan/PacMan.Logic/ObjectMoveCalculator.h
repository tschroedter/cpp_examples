#pragma once

#include "IObjectMoveCalculator.h"
#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        class ObjectMoveCalculator
            : public IObjectMoveCalculator
        {
        private:
            IPlayingField_Ptr m_playing_field;

            static Column move_left ( const Column& column );
            Column move_right ( const Column& column ) const;
            static Row move_up ( const Row& row );
            Row move_down ( const Row& row ) const;

        public:
            ObjectMoveCalculator ();
            ~ObjectMoveCalculator ();

            void calculate ( Row from_row,
                             Column from_column,
                             Heading heading ) override;

            void initialize ( const IPlayingField_Ptr& playing_field ) override;
        };
    }
}
