#include "stdafx.h"

#include "DisplayPlayingField.h"
#include "DisplayPlayingFieldException.h"

namespace PacMan
{
    namespace View
    {
        IDisplayPlayingFieldObject_Ptr** DisplayPlayingField::create_field (
            const size_t rows,
            const size_t columns )
        {
            IDisplayPlayingFieldObject_Ptr** field = new IDisplayPlayingFieldObject_Ptr*[rows];

            for ( size_t i = 0 ; i < rows ; i++ )
            {
                IDisplayPlayingFieldObject_Ptr* row = new IDisplayPlayingFieldObject_Ptr[columns];

                for ( size_t j = 0 ; j < columns ; j++ )
                {
                    row [ j ] = nullptr;
                }

                field [ i ] = row;
            }

            return field;
        }

        void DisplayPlayingField::initialize (
            const Logic::IPlayingField_Ptr playing_field )
        {
            m_playing_field = playing_field;

            size_t rows = playing_field->get_rows();
            size_t columns = playing_field->get_columns();

            m_validator->initialize (
                                     rows,
                                     columns );

            m_mapping->initialize();

            m_field = create_field (
                                    rows,
                                    columns );
        }

        size_t DisplayPlayingField::get_rows () const
        {
            return m_playing_field->get_rows();
        }

        size_t DisplayPlayingField::get_columns () const
        {
            return m_playing_field->get_columns();
        }

        void DisplayPlayingField::update_field () const
        {
            using namespace PacMan::Logic;

            size_t rows = m_playing_field->get_rows();
            size_t columns = m_playing_field->get_columns();

            for ( size_t row = 0 ; row < rows ; row++ )
            {
                for ( size_t column = 0 ; column < columns ; column++ )
                {
                    IPlayingFieldObject_Ptr object =
                            m_playing_field->get_object_at ( row, column );

                    IDisplayPlayingFieldObject_Ptr display_object =
                            m_mapping->get_object_for ( object );

                    put_object_at ( display_object, row, column );
                }
            }
        }

        void DisplayPlayingField::display_field () const
        {
            using namespace PacMan::Logic;

            size_t rows = m_playing_field->get_rows();
            size_t columns = m_playing_field->get_columns();

            for ( size_t row = 0 ; row < rows ; row++ )
            {
                for ( size_t column = 0 ; column < columns ; column++ )
                {
                    IDisplayPlayingFieldObject_Ptr object =
                            get_object_at ( row, column );

                    m_out << object->to_string();
                }

                m_out << "\n";
            }
        }

        void DisplayPlayingField::print ()
        {
            if ( m_playing_field == nullptr )
            {
                throw DisplayPlayingFieldException ( "Given IPlayingField_Ptr is nullptr!" );
            }

            update_field();
            display_field();
        }

        IDisplayPlayingFieldObject_Ptr DisplayPlayingField::get_object_at (
            const size_t row,
            const size_t column ) const
        {
            m_validator->validate_row ( row );
            m_validator->validate_column ( column );

            IDisplayPlayingFieldObject_Ptr* selected_row = m_field [ row ];
            IDisplayPlayingFieldObject_Ptr object = selected_row [ column ];

            return object;
        }

        void DisplayPlayingField::put_object_at (
            const IDisplayPlayingFieldObject_Ptr object,
            const size_t row,
            const size_t column ) const
        {
            // todo m_validator->validate_object(object);
            m_validator->validate_row ( row );
            m_validator->validate_column ( column );

            IDisplayPlayingFieldObject_Ptr* selected_row = m_field [ row ];
            selected_row [ column ] = object;
        }
    }
}
