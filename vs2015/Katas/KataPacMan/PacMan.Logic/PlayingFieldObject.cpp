#include "stdafx.h"
#include "PlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        PlayingFieldObjectType PlayingFieldObject::get_type () const
        {
            return m_type;
        }

        Heading PlayingFieldObject::get_heading () const
        {
            return m_direction->get_heading();
        }

        void PlayingFieldObject::set_heading ( Heading heading )
        {
            m_direction->set_heading(heading);
        }

        void PlayingFieldObject::tick ()
        {
        }

        bool PlayingFieldObject::is_moveable () const
        {
            return false;
        }

        bool PlayingFieldObject::is_moving () const
        {
            return false;
        }
    }
}
