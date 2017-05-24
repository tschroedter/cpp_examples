#include "stdafx.h"

#include <string>
#include "PlayingFieldException.h"
#include "PlayingFieldValidator.h"

namespace PacMan
{
    namespace Logic
    {
        void PlayingFieldValidator::validate_rows_and_columns (
            const size_t rows,
            const size_t columns ) const
        {
            if ( rows <= 0 )
            {
                throw PlayingFieldException (
                                             "Given value for rows is invalid! ("
                                             + std::to_string ( rows )
                                             + " < 0)!" );
            }

            if ( columns <= 0 )
            {
                throw PlayingFieldException (
                                             "Given value for columns is invalid! ("
                                             + std::to_string ( columns )
                                             + " < 0)!" );
            }
        }

        void PlayingFieldValidator::initialize ( const size_t rows, const size_t columns )
        {
            m_rows = rows;
            m_columns = columns;
        }

        size_t PlayingFieldValidator::get_rows () const
        {
            return m_rows;
        }

        size_t PlayingFieldValidator::get_columns () const
        {
            return m_columns;
        }

        void PlayingFieldValidator::validate_row ( const size_t row ) const
        {
            if ( row < 0 || row >= m_rows )
            {
                throw PlayingFieldException (
                                             "Given value for row '"
                                             + std::to_string ( row )
                                             + "' is invalid! (row < 0 or row >= "
                                             + std::to_string ( m_rows )
                                             + ")" );
            }
        }

        void PlayingFieldValidator::validate_column ( const size_t column ) const
        {
            if ( column < 0 || column >= m_columns )
            {
                throw PlayingFieldException (
                                             "Given value for row '"
                                             + std::to_string ( column )
                                             + "' is invalid! (row < 0 or row >= "
                                             + std::to_string ( m_columns )
                                             + ")" );
            }
        }

        void PlayingFieldValidator::validate_object ( const IPlayingFieldObject_Ptr object ) const
        {
            if ( object == nullptr )
            {
                throw PlayingFieldException (
                                             "Given value for object is invalid! (nullptr)" );
            }
        }
    }
}
