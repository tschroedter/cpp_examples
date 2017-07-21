#include "stdafx.h"
#include "Heading.h"
#include "Direction.h"

namespace PacMan
{
    namespace Logic
    {
        Heading Direction::get_heading () const
        {
            return m_heading;
        }

        void Direction::set_heading ( Heading heading )
        {
            m_heading = heading;
        }
    };
};
