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

        ILocation_Ptr PlayingFieldObject::get_location () const
        {
            return m_location;
        }

        Heading PlayingFieldObject::get_heading () const
        {
            return m_direction->get_heading();
        }

        void PlayingFieldObject::tick ()
        {
        }
    }
}