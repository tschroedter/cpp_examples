#include "stdafx.h"
#include "DisplayPacMan.h"

namespace PacMan
{
    namespace View
    {
        DisplayObjectType DisplayPacMan::get_type () const
        {
            return m_type;
        }

        void DisplayPacMan::initialize ( const Logic::IPlayingFieldObject_Ptr object )
        {
            m_object = object;

            m_heading_to_string[Logic::Heading_Unknown] = PacMan_Unknown;
            m_heading_to_string[Logic::Heading_Up] = PacMan_Up;
            m_heading_to_string[Logic::Heading_Down] = PacMan_Down;
            m_heading_to_string[Logic::Heading_Left] = PacMan_Left;
            m_heading_to_string[Logic::Heading_Right] = PacMan_Right;
            m_heading_to_string[Logic::Heading_Max] = PacMan_Max;
        }

        std::string DisplayPacMan::to_string ()
        {
            Logic::Heading heading = m_object->get_heading();
            std::string cs = m_heading_to_string[heading];
            return cs;
        }
    };
};
