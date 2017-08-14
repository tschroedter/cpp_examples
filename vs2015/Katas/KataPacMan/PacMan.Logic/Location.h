#pragma once

#include "ILocation.h"

namespace PacMan
{
    namespace Logic
    {
        class Location
            : public ILocation
        {
        private:
            Row m_row = 3;
            Column m_column = 3;

        public:
            Location ()
            {
            }

            Location (
                Row row,
                Column column )
                : m_row(row)
                  , m_column(column)
            {
            }

            Row get_row () const override;
            Column get_column () const override;
        };
    };
};
