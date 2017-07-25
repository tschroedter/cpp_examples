#include "stdafx.h"
#include "ObjectsMover.h"
#include "IPlayingField.h"
#include "MoveObjectInformation.h"
#include <iostream>

namespace PacMan
{
    namespace Logic
    {
        ObjectsMover::ObjectsMover (
            const IObjectMoveCalculator_Ptr calculator,
            const IMovingObjectsRepository_Ptr repository )
            : m_calculator(calculator),
              m_repository(repository)
        {
        }

        void ObjectsMover::initialize (
            const IPlayingField_Ptr& playing_field )
        {
            m_playing_field = playing_field;
            m_calculator->initialize(playing_field);
        }

        void ObjectsMover::add_move_to_repository (
            size_t row,
            size_t column,
            IPlayingFieldObject_Ptr object ) const
        {
            Heading heading = object->get_heading();

            m_calculator->calculate(row,
                                    column,
                                    heading);

            auto p_info = new MoveObjectInformation{};
            IMoveObjectInformation_Ptr shared(p_info);

            shared->from_row = row;
            shared->from_column = column;
            shared->to_row = m_calculator->to_row;
            shared->to_column = m_calculator->to_column;
            shared->playing_field_object_type = object->get_type();

            m_repository->add(shared);
        }

        void ObjectsMover::calculate ()
        {
            m_repository->clear();

            size_t number_of_rows = m_playing_field->get_rows();
            size_t number_of_columns = m_playing_field->get_columns();

            for (size_t row = 0; row < number_of_rows; row++)
            {
                for (size_t column = 0; column < number_of_columns; column++)
                {
                    auto object = m_playing_field->get_object_at(row,
                                                                 column);

                    if (!object->is_moving())
                    {
                        continue;
                    }

                    add_move_to_repository(row, column, object);
                }
            }
        }

        void ObjectsMover::print_moves () const
        {
            int counter = 0;
            auto all = m_repository->get_all();

            for (auto iter = all->begin(); iter != all->end();
                 ++iter)
            {
                IMoveObjectInformation_Ptr info = (*iter);

                std::cout
                    << "[" << counter << "]"
                    << " (" << info->from_row
                    << " , " << info->from_column
                    << ") --> (" << info->to_row
                    << ", " << info->to_column
                    << ") Type: " << info->playing_field_object_type
                    << "\n";

                counter++;
            }
        }

        void ObjectsMover::move_objects () const
        {
            auto all = m_repository->get_all();

            for (auto iter = all->begin(); iter != all->end();
                 ++iter)
            {
                IMoveObjectInformation_Ptr info = (*iter);

                // todo take into account info->type
                m_playing_field->move_object_from_to(info->from_row,
                                                     info->from_column,
                                                     info->to_row,
                                                     info->to_column);
            }
        }
    }
}
