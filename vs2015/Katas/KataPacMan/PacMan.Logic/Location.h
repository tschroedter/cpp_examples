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
            size_t m_row = 3;
            size_t m_column = 3;
        public:
            Location ()
            {
            }

            Location (
                size_t row,
                size_t column )
                : m_row ( row )
                , m_column ( column )
            {
            }

            size_t get_row () const override;
            size_t get_column () const override;
        };
    };
};
