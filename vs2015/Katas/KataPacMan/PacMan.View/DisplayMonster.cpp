#include "stdafx.h"
#include "DisplayMonster.h"

namespace PacMan
{
    namespace View
    {
        DisplayObjectType DisplayMonster::get_type () const
        {
            return m_type;
        }

        void DisplayMonster::initialize ( const Logic::IPlayingFieldObject_Ptr object )
        {
            m_object = object;
        }

        std::string DisplayMonster::to_string () const
        {
            return m_to_string;
        }
    };
};
