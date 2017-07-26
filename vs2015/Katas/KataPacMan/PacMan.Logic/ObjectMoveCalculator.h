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

            size_t move_left ( const size_t& column ) const;
            size_t move_right ( const size_t& column ) const;
            size_t move_up ( const size_t& row ) const;
            size_t move_down ( const size_t& row ) const;

        public:
            ObjectMoveCalculator ();
            ~ObjectMoveCalculator ();

            void calculate ( size_t from_row,
                             size_t from_column,
                             Heading heading ) override;

            void initialize ( const IPlayingField_Ptr& playing_field ) override;
        };
    }
}
