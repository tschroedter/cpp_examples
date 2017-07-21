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

        Heading Monster::get_heading () const
        {
            return PlayingFieldObject::get_heading();
        }

        void Monster::set_heading ( Heading heading )
        {
            PlayingFieldObject::set_heading(heading);  // todo testing
        }

        bool Monster::is_moving() const
        {
            auto heading = get_heading();

            return
                (heading != Heading_Unknown) &&
                (heading != Heading_Max);
        }

        void Monster::tick ()
        {       
            // todo remove??
        }
    }
}
