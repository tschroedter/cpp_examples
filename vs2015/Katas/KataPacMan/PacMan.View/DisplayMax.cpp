#include "stdafx.h"
#include "DisplayMax.h"

namespace PacMan
{
    namespace View
    {
        DisplayObjectType DisplayMax::get_type () const
        {
            return m_type;
        }

        void DisplayMax::initialize ( const Logic::IPlayingFieldObject_Ptr object )
        {
            m_object = object;
        }

        std::string DisplayMax::to_string () const
        {
            return m_to_string;
        }
    };
};
