#include "stdafx.h"
#include "ObjectsMover.h"
#include "IPlayingField.h"
#include <iostream>
#include "IObjectsMoveExecuter.h"
#include "IObjectsMoveValidator.h"

namespace PacMan
{
    namespace Logic
    {
        ObjectsMover::ObjectsMover (
            const IObjectsMoverCalculator_Ptr calculator,
            const IMovingObjectsRepository_Ptr repository,
            const IObjectsMoveExecuter_Ptr executer,
            const IObjectsMoveValidator_Ptr validator)
            : m_calculator(calculator),
              m_repository(repository),
              m_executer(executer),
              m_validator(validator)
        {
        }

        void ObjectsMover::initialize (
            const IPlayingField_Ptr& playing_field )
        {   // todo use singeltons ?
            m_playing_field = playing_field;
            m_calculator->initialize(playing_field,
                                     m_repository);
            m_executer->initialize(playing_field,
                                   m_repository);
            m_validator->initialize(m_repository);
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
            m_validator->validate_moves();
            m_executer->move_objects();
        }

        ValidationStatus ObjectsMover::get_status() const
        {
            return m_validator->get_status();
        }
    }
}
