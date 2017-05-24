#include "stdafx.h"
#include "Monster.h"

namespace PacMan
{
    namespace Logic
    {
        PlayingFieldObjectType Monster::get_type () const
        {
            return PlayingFieldObject::get_type();
        }

        ILocation_Ptr Monster::get_location () const
        {
            return PlayingFieldObject::get_location();
        }

        Heading Monster::get_heading () const
        {
            return PlayingFieldObject::get_heading();
        }

        void Monster::tick ()
        {
        }
    }
}
