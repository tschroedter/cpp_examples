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

        Heading Dot::get_heading () const
        {
            return PlayingFieldObject::get_heading();
        }

        void Dot::set_heading ( Heading heading )
        {
            PlayingFieldObject::set_heading(heading);   // todo testing
        }

        bool Dot::is_moving() const
        {
            return false;
        }

        void Dot::tick ()
        {
        }

        bool Dot::is_moveable () const
        {
            return false; // todo testing
        }
    }
}
