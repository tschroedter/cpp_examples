#include "stdafx.h"
#include "ObjectMover.h"
#include <iostream>
#include "IPlayingField.h"
#include "GameTimer.h"


namespace PacMan
{
    namespace Logic
    {
        ObjectMover::ObjectMover ()
        {
        }

        ObjectMover::~ObjectMover ()
        {
        }

        void ObjectMover::initialize ( const IPlayingField_Ptr& playing_field )
        {
            m_playing_field = playing_field;
        }

        bool ObjectMover::is_moveable_object ( const IPlayingFieldObject_Ptr object )
        {
            return object->get_type() != PlayingFieldObjectType_Unknown &&
                object->get_type() != PlayingFieldObjectType_Dot &&
                object->get_type() != PlayingFieldObjectType_Max;
        }

        size_t ObjectMover::move_left ( const size_t& column ) const
        {
            return
                column >= 1 ? column-1
                    : 0;
        }

        size_t ObjectMover::move_right(const size_t& column) const
        {
            auto max_columns = m_playing_field->get_columns();

            return
                column > max_columns 
                ? column+1
                : max_columns-1;
        }

        size_t ObjectMover::move_up(const size_t& row) const
        {
            return
                row >= 1 ? row - 1
                : 0;
        }

        size_t ObjectMover::move_down(const size_t& row) const
        {
            auto max_rows = m_playing_field->get_rows();

            return
                row > max_rows
                ? row + 1
                : max_rows - 1;
        }

        void ObjectMover::move_object (
            const size_t from_row,
            const size_t from_column )
        {
            const IPlayingFieldObject_Ptr object =
                m_playing_field->get_object_at(from_row,
                                               from_column);

            if (!is_moveable_object(object))
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
                size_t to_row = from_row;
                size_t to_column = from_column;

                auto heading = object->get_heading();

                switch (heading)
                {
                case Heading_Left:
                    to_column = move_left(to_column);
                    break;
                case Heading_Right:
                    to_column = move_right(to_column);
                    break;
                case Heading_Up:
                    to_row = move_up(to_row);
                    break;
                case Heading_Down:
                    to_row = move_down(to_row);
                    break;
                case Heading_Unknown:
                case Heading_Max:
                    break;
                default:
                    break;
                }

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
