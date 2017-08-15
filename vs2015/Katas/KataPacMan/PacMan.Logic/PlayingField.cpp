#include "stdafx.h"

#include "PlayingField.h"
#include <string>
#include "Dot.h"

namespace PacMan
{
    namespace Logic
    {
        IPlayingFieldObject_Ptr** PlayingField::create_field (
            const Row rows,
            const Column columns ) const
        {
            m_validator->validate_rows_and_columns(rows, columns);

            IPlayingFieldObject_Ptr** field = new IPlayingFieldObject_Ptr*[rows];

            for (Row i = 0; i < rows; i++)
            {
                IPlayingFieldObject_Ptr* row = new IPlayingFieldObject_Ptr[columns];

                for (Column j = 0; j < columns; j++)
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
            const Row rows,
            const Column columns )
        {
            m_rows = rows;
            m_columns = columns;

            m_field = create_field(rows, columns);

            m_validator->initialize(rows, columns);
        }

        Row PlayingField::get_rows () const
        {
            return m_rows;
        }

        Column PlayingField::get_columns () const
        {
            return m_columns;
        }

        IPlayingFieldObject_Ptr PlayingField::get_object_at (
            const Row row,
            const Column column )
        {
            m_validator->validate_row(row);
            m_validator->validate_column(column);

            IPlayingFieldObject_Ptr* selected_row = m_field[row];
            IPlayingFieldObject_Ptr object = selected_row[column];

            return object;
        }

        PlayingFieldObjectType PlayingField::get_object_type_at ( const Row row, const Column column )
        {
            IPlayingFieldObject_Ptr object = get_object_at(row, column);

            return object->get_type();
        }

        void PlayingField::put_object_at (
            const IPlayingFieldObject_Ptr object,
            const Row row,
            const Column column )
        {
            m_validator->validate_object(object);
            m_validator->validate_row(row);
            m_validator->validate_column(column);

            IPlayingFieldObject_Ptr* selected_row = m_field[row];
            selected_row[column] = object;
        }

        void PlayingField::move_object_from_to (
            const Row from_row,
            const Column from_column,
            const Row to_row,
            const Column to_column )
        {
            if (from_row == to_row &&
                from_column == to_column)
            {
                return;
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
