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
            Row m_rows;
            Column m_columns;

        public:
            PlayingFieldValidator ()
                : m_rows(Row(0)),
                  m_columns(Column(0))
            {
            }

            ~PlayingFieldValidator ()
            {
            }

            void initialize (
                const Row rows,
                const Column columns ) override;

            Row get_rows () const override;
            Column get_columns () const override;

            void validate_object ( const IPlayingFieldObject_Ptr object ) const override;
            void validate_row ( const Row row ) const override;
            void validate_column ( const Column column ) const override;
            void validate_rows_and_columns (
                const Row rows,
                const Column columns ) const override;
        };
    };
};
