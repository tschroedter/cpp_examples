#include "stdafx.h"
#include "ObjectMover.h"
#include <iostream>
#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        ObjectMover::ObjectMover (
            IObjectMoveCalculator_Ptr calculator )
            : m_calculator(calculator)
        {
        }

        ObjectMover::~ObjectMover ()
        {
        }

        void ObjectMover::initialize ( const IPlayingField_Ptr& playing_field )
        {
            m_playing_field = playing_field;
            m_calculator->initialize(playing_field);
        }

        void ObjectMover::move_object (
            const size_t from_row,
            const size_t from_column )
        {
            const IPlayingFieldObject_Ptr object =
                m_playing_field->get_object_at(from_row,
                                               from_column);

            if (!object->is_moveable())
            {
                std::cout
                    << "Not moveable object of type '"
                    << object->get_type()
                    << "' at "
                    << from_row
                    << ", "
                    << from_column
                    << "\n";

                return;
            }

            if (object->is_moving())
            {
                auto heading = object->get_heading();

                m_calculator->calculate(
                                        from_row,
                                        from_column,
                                        heading);

                size_t to_row = m_calculator->to_row;
                size_t to_column = m_calculator->to_column;

                m_playing_field->move_object_from_to(
                                                     from_row,
                                                     from_column,
                                                     to_row,
                                                     to_column);

                std::cout
                    << "Moving object of type '"
                    << object->get_type()
                    << "' from "
                    << from_row
                    << ","
                    << from_column
                    << " to "
                    << to_row
                    << ","
                    << to_column
                    << "\n";
            }
        }
    }
}
