#include "stdafx.h"

#include "PlayingField.h"
#include <string>
#include "Dot.h"

namespace PacMan
{
    namespace Logic
    {
        IPlayingFieldObject_Ptr** PlayingField::create_field (
            const size_t rows,
            const size_t columns ) const
        {
            m_validator->validate_rows_and_columns(rows, columns);

            IPlayingFieldObject_Ptr** field = new IPlayingFieldObject_Ptr*[rows];

            for (size_t i = 0; i < rows; i++)
            {
                IPlayingFieldObject_Ptr* row = new IPlayingFieldObject_Ptr[columns];

                for (size_t j = 0; j < columns; j++)
                {
                    IDot_Ptr dot = m_factory();
                    // todo dot.initialize();
                    row[j] = dot;
                }

                field[i] = row;
            }

            return field;
        }

        void PlayingField::initialize (
            const size_t rows,
            const size_t columns )
        {
            m_rows = rows;
            m_columns = columns;

            m_field = create_field(rows, columns);

            m_validator->initialize(rows, columns);
        }

        size_t PlayingField::get_rows () const
        {
            return m_rows;
        }

        size_t PlayingField::get_columns () const
        {
            return m_columns;
        }

        IPlayingFieldObject_Ptr PlayingField::get_object_at (
            const size_t row,
            const size_t column )
        {
            m_validator->validate_row(row);
            m_validator->validate_column(column);

            IPlayingFieldObject_Ptr* selected_row = m_field[row];
            IPlayingFieldObject_Ptr object = selected_row[column];

            return object;
        }

        PlayingFieldObjectType PlayingField::get_object_type_at ( const size_t row, const size_t column )
        {
            IPlayingFieldObject_Ptr object = get_object_at(row, column);

            return object->get_type();
        }

        void PlayingField::put_object_at (
            const IPlayingFieldObject_Ptr object,
            const size_t row,
            const size_t column )
        {
            m_validator->validate_object(object);
            m_validator->validate_row(row);
            m_validator->validate_column(column);

            IPlayingFieldObject_Ptr* selected_row = m_field[row];
            selected_row[column] = object;
        }

        void PlayingField::move_object_from_to (
            const size_t from_row,
            const size_t from_column,
            const size_t to_row,
            const size_t to_column )
        {
            if (from_row == to_row &&
                from_column == to_column)
            {
                return; // todo testing
            }

            m_validator->validate_row(from_row);
            m_validator->validate_column(from_column);

            m_validator->validate_row(to_row);
            m_validator->validate_column(to_column);

            auto object = get_object_at(from_row, from_column);
            put_object_at(object, to_row, to_column);

            IDot_Ptr dot = m_factory();
            put_object_at(dot, from_row, from_column);
        }
    }
}
