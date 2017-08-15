#include "stdafx.h"
#include "DisplayDot.h"

namespace PacMan
{
    namespace View
    {
        DisplayObjectType DisplayDot::get_type () const
        {
            return m_type;
        }

        void DisplayDot::initialize ( const Logic::IPlayingFieldObject_Ptr object )
        {
            m_object = object;
        }

        std::string DisplayDot::to_string () const
        {
            return m_to_string;
        }
    };
};
