#include "stdafx.h"
#include "PacMan.h"

namespace PacMan
{
    namespace Logic
    {
        PlayingFieldObjectType PacMan::get_type () const
        {
            return PlayingFieldObject::get_type();
        }

        ILocation_Ptr PacMan::get_location () const
        {
            return PlayingFieldObject::get_location();
        }

        Heading PacMan::get_heading () const
        {
            return PlayingFieldObject::get_heading();
        }

        void PacMan::tick ()
        {
        }
    }
}
