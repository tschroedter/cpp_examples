﻿#include "stdafx.h"
#include "ObjectMoveCalculator.h"
#include "Heading.h"
#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        ObjectMoveCalculator::ObjectMoveCalculator ()
        {
        }

        ObjectMoveCalculator::~ObjectMoveCalculator ()
        {
        }

        void ObjectMoveCalculator::initialize ( const IPlayingField_Ptr& playing_field )
        {
            m_playing_field = playing_field;
        }

        void ObjectMoveCalculator::calculate (
            const Row from_row,
            const Column from_column,
            const Heading heading )
        {
            to_row = from_row;
            to_column = from_column;

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
        }

        Column ObjectMoveCalculator::move_left ( const Column& column )
        {
            return
                column >= 1 ? column - 1
                    : 0;
        }

        Column ObjectMoveCalculator::move_right ( const Column& column ) const
        {
            auto max_columns = m_playing_field->get_columns();

            return
                column < (max_columns - 1)
                    ? column + 1
                    : max_columns - 1;
        }

        Row ObjectMoveCalculator::move_up ( const Row& row )
        {
            return
                row >= 1 ? row - 1
                    : 0;
        }

        Row ObjectMoveCalculator::move_down ( const Row& row ) const
        {
            auto max_rows = m_playing_field->get_rows();

            return
                row < (max_rows - 1)
                    ? row + 1
                    : max_rows - 1;
        }
    }
}
