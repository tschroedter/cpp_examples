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

        Heading PacMan::get_heading () const
        {
            return PlayingFieldObject::get_heading();
        }

        bool PacMan::is_moving() const
        {
            auto heading = get_heading();

            return 
                (heading != Heading_Unknown) &&
                (heading != Heading_Max);
        }

        void PacMan::tick ()
        {
        }
    }
}
