#include "stdafx.h"
#include "Dot.h"

namespace PacMan
{
    namespace Logic
    {
        PlayingFieldObjectType Dot::get_type () const
        {
            return PlayingFieldObject::get_type();
        }

        ILocation_Ptr Dot::get_location () const
        {
            return PlayingFieldObject::get_location();
        }

        Heading Dot::get_heading () const
        {
            return PlayingFieldObject::get_heading();
        }

        void Dot::tick ()
        {
        }
    }
}
