#pragma once

#include "IPlayingField.h"
#include "IPlayingFieldValidator.h"

namespace PacMan
{
    namespace Logic
    {
        class PlayingFieldValidator
                : public IPlayingFieldValidator
        {
        private:
            size_t m_rows;
            size_t m_columns;

        public:
            PlayingFieldValidator ()
                : m_rows ( size_t ( 0 ) )
                , m_columns ( size_t ( 0 ) )
            {
            }

            ~PlayingFieldValidator ()
            {
            }

            void initialize (
                const size_t rows,
                const size_t columns ) override;

            size_t get_rows () const override;
            size_t get_columns () const override;

            void validate_object ( const IPlayingFieldObject_Ptr object ) const override;
            void validate_row ( const size_t row ) const override;
            void validate_column ( const size_t column ) const override;
            void validate_rows_and_columns (
                const size_t rows,
                const size_t columns ) const override;
        };
    };
};
