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

        void PacMan::set_heading ( Heading heading )
        {
            PlayingFieldObject::set_heading(heading);
        }

        bool PacMan::is_moving () const
        {
            auto heading = get_heading();

            return
                (heading != Heading_Unknown) &&
                (heading != Heading_Max);
        }

        void PacMan::tick ()
        {
        }

        bool PacMan::is_moveable () const
        {
            return true;
        }
    }
}
