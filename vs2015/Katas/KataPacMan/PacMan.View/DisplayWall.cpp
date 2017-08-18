#include "stdafx.h"
#include "DisplayWall.h"

namespace PacMan
{
    namespace View
    {
        DisplayObjectType DisplayWall::get_type () const
        {
            return m_type;
        }

        void DisplayWall::initialize ( const Logic::IPlayingFieldObject_Ptr object )
        {
            m_object = object;
        }

        std::string DisplayWall::to_string () const
        {
            return m_to_string;
        }
    };
};
