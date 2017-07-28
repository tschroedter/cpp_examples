#pragma once
#include "IObjectsMover.h"
#include "IObjectMoveCalculator.h"
#include "MovingObjectsRepository.h"
#include "IObjectsMoverCalculator.h"

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

        public:
            ObjectsMover ( const IObjectsMoverCalculator_Ptr calculator,
                           const IMovingObjectsRepository_Ptr repository );
            ~ObjectsMover () = default;

            void ObjectsMover::initialize (
                const IPlayingField_Ptr& playing_field ) override;
            void calculate () override;
            std::ostream& print_moves ( std::ostream& out ) const override;
            void move_objects () const override;

            friend std::ostream& operator<< (
                std::ostream& out,
                const IObjectsMover& mover )
            {
                // Delegate printing responsibility for printing to member function print()
                return mover.print_moves(out);
            }
        };
    }
}
