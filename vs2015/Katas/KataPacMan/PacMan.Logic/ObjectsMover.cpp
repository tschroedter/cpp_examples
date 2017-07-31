#include "stdafx.h"
#include "ObjectsMover.h"
#include "IPlayingField.h"
#include <iostream>
#include "IObjectsMoveExecuter.h"

namespace PacMan
{
    namespace Logic
    {
        ObjectsMover::ObjectsMover (
            const IObjectsMoverCalculator_Ptr calculator,
            const IMovingObjectsRepository_Ptr repository,
            const IObjectsMoveExecuter_Ptr executer )
            : m_calculator(calculator),
              m_repository(repository),
              m_executer(executer)
        {
        }

        void ObjectsMover::initialize (
            const IPlayingField_Ptr& playing_field )
        {
            m_playing_field = playing_field;
            m_calculator->initialize(playing_field,
                                     m_repository);
            m_executer->initialize(playing_field,
                                   m_repository);
        }

        void ObjectsMover::calculate ()
        {
            m_calculator->calculate();
        }

        std::ostream& ObjectsMover::print_moves ( std::ostream& out ) const
        {
            return m_repository->print_moves(out);
        }

        void ObjectsMover::move_objects () const
        {
            m_executer->move_objects();
        }
    }
}
