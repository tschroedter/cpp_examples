#include "stdafx.h"
#include "DisplayUnknown.h"

namespace PacMan
{
    namespace View
    {
        DisplayObjectType DisplayUnknown::get_type () const
        {
            return m_type;
        }

        void DisplayUnknown::initialize ( const Logic::IPlayingFieldObject_Ptr object )
        {
            m_object = object;
        }

        std::string DisplayUnknown::to_string ()
        {
            return m_to_string;
        }
    };
};
