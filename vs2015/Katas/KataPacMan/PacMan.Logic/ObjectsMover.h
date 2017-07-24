#pragma once
#include "IObjectsMover.h"
#include "IObjectMoveCalculator.h"
#include "MovingObjectsRepository.h"

namespace PacMan
{
    namespace Logic
    {
        class ObjectsMover // todo testing
            : IObjectsMover
        {
        private:
            IPlayingField_Ptr m_playing_field;
            IObjectMoveCalculator_Ptr m_calculator;
            IMovingObjectsRepository_Ptr m_repository;

        public:
            ObjectsMover ( const IObjectMoveCalculator_Ptr calculator,
                           const IMovingObjectsRepository_Ptr repository );
            ~ObjectsMover () = default;

            void ObjectsMover::initialize ( const IPlayingField_Ptr playing_field ) override;
            void move_objects () override;
        };
    }
}
