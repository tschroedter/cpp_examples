#pragma once
#include "IObjectMover.h"
#include "IPlayingField.h"
#include "IObjectMoveCalculator.h"

namespace PacMan
{
    namespace Logic
    {
        class ObjectMover
            : public IObjectMover
        {
        private:
            IObjectMoveCalculator_Ptr m_calculator;
            IPlayingField_Ptr m_playing_field;

        public:
            ObjectMover::ObjectMover ( IObjectMoveCalculator_Ptr calculator );

            ~ObjectMover ();

            void ObjectMover::move_object (
                const size_t from_row,
                const size_t from_columns ) override;

            void initialize ( const IPlayingField_Ptr& playing_field ) override;
        };
    };
};
