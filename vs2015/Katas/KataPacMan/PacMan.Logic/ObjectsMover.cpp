#include "stdafx.h"
#include "ObjectsMover.h"
#include "IPlayingField.h"
#include <iostream>

namespace PacMan
{
    namespace Logic
    {
        ObjectsMover::ObjectsMover (
            const IObjectsMoverCalculator_Ptr calculator,
            const IMovingObjectsRepository_Ptr repository )
            : m_calculator(calculator),
              m_repository(repository) // todo check this
        {
        }

        void ObjectsMover::initialize (
            const IPlayingField_Ptr& playing_field )
        {
            m_playing_field = playing_field;
            m_calculator->initialize(playing_field,
                                     m_repository);// todo and this
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
        { // todo testing and move into class
            auto all_pac_mans = m_repository->get_all_of_type(PlayingFieldObjectType_PacMan); // there should be only one

            for (auto info : (*all_pac_mans))
            {
                m_playing_field->move_object_from_to(info->from_row,
                                                     info->from_column,
                                                     info->to_row,
                                                     info->to_column);
            }

            auto all_monsters = m_repository->get_all_of_type(PlayingFieldObjectType_Monster);

            for (auto info : (*all_monsters))
            {
                m_playing_field->move_object_from_to(info->from_row,
                                                     info->from_column,
                                                     info->to_row,
                                                     info->to_column);
            }
        }
    }
}
