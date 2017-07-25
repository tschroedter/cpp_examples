#pragma once
#include "IObjectsMover.h"
#include "IObjectMoveCalculator.h"
#include "MovingObjectsRepository.h"
#include "IObjectMover.h"

namespace PacMan
{
    namespace Logic
    {
        class ObjectsMover // todo testing
            : public IObjectsMover
        {
        private:
            IPlayingField_Ptr m_playing_field;
            IObjectMoveCalculator_Ptr m_calculator;
            IMovingObjectsRepository_Ptr m_repository;

        public:
            ObjectsMover ( const IObjectMoveCalculator_Ptr calculator,
                           const IMovingObjectsRepository_Ptr repository);
            ~ObjectsMover () = default;

            void ObjectsMover::initialize ( const IPlayingField_Ptr& playing_field ) override;
            void add_move_to_repository ( size_t row, size_t column, IPlayingFieldObject_Ptr object ) const;
            void calculate () override;
            void print_moves () const override;
            void move_objects () const override;
        };
    }
}
