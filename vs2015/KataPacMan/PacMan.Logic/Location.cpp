#include "stdafx.h"
#include "Location.h"

namespace PacMan
{
    namespace Logic
    {
        size_t Location::get_row () const
        {
            return m_row;
        }

        size_t Location::get_column () const
        {
            return m_column;
        }
    }
}
