#pragma once
#include "IObjectsMoverCalculator.h"
#include "IMovingObjectsRepository.h"
#include "IObjectMoveCalculator.h"

namespace PacMan
{
    namespace Logic
    {
        class ObjectsMoverCalculator
            : public IObjectsMoverCalculator
        {
        public:
            ObjectsMoverCalculator ( const IObjectMoveCalculator_Ptr calculator );

            ~ObjectsMoverCalculator () = default;

            void initialize (
                const IPlayingField_Ptr playing_field,
                const IMovingObjectsRepository_Ptr repository ) override;

            void calculate () const override;

            IMoveObjectInformation_Ptr create_info (
                size_t row,
                size_t column,
                IPlayingFieldObject_Ptr object ) const;

        private:
            IPlayingField_Ptr m_playing_field;
            IObjectMoveCalculator_Ptr m_calculator;
            IMovingObjectsRepository_Ptr m_repository;
        };
    }
}
