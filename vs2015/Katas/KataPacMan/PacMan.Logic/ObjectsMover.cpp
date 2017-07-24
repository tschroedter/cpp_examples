#include "stdafx.h"
#include "ObjectsMover.h"
#include "IPlayingField.h"
#include "MoveObjectInformation.h"

namespace PacMan
{
    namespace Logic
    {
        ObjectsMover::ObjectsMover (
            const IObjectMoveCalculator_Ptr calculator,
            const IMovingObjectsRepository_Ptr repository )
            : m_calculator(calculator), m_repository(repository)
        {
        }

        void ObjectsMover::initialize (
            const IPlayingField_Ptr playing_field )
        {
            m_playing_field = playing_field;
        }

        void ObjectsMover::move_objects ()
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

                    Heading heading = object->get_heading();

                    m_calculator->calculate(row,
                                            column,
                                            heading);

                    // todo add move to list...
                    m_repository->add(row,
                                      column,
                                      m_calculator->to_row,
                                      m_calculator->to_column,
                                      object->get_type());

                    // MoveObjectInformation -> need repository
                }
            }
        }
    }
}
