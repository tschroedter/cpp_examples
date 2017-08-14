#include "stdafx.h"
#include "Location.h"

namespace PacMan
{
    namespace Logic
    {
        Row Location::get_row () const
        {
            return m_row;
        }

        Column Location::get_column () const
        {
            return m_column;
        }
    }
}
