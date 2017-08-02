#pragma once
#include "IObjectsMover.h"
#include "IObjectMoveCalculator.h"
#include "MovingObjectsRepository.h"
#include "IObjectsMoverCalculator.h"
#include "IObjectsMoveExecuter.h"
#include "IObjectsMoveValidator.h"

namespace PacMan
{
    namespace Logic
    {
        class ObjectsMover // todo testing
            : public IObjectsMover
        {
        private:
            IObjectsMoverCalculator_Ptr m_calculator;
            IPlayingField_Ptr m_playing_field;
            IMovingObjectsRepository_Ptr m_repository;
            IObjectsMoveExecuter_Ptr m_executer;
            IObjectsMoveValidator_Ptr m_validator;

        public:
            ObjectsMover ( const IObjectsMoverCalculator_Ptr calculator,
                           const IMovingObjectsRepository_Ptr repository,
                           const IObjectsMoveExecuter_Ptr executer,
                           const IObjectsMoveValidator_Ptr validator);
            ~ObjectsMover () = default;

            void ObjectsMover::initialize (
                const IPlayingField_Ptr& playing_field ) override;
            void calculate () override;
            std::ostream& print_moves ( std::ostream& out ) const override;
            void move_objects () const override;
            ValidationStatus get_status () const override;

            friend std::ostream& operator<< (
                std::ostream& out,
                const IObjectsMover& mover )
            {
                return mover.print_moves(out);
            }
        };
    }
}
