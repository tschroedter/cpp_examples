#include "stdafx.h"
#include <iostream>
#include "Heading.h"
#include "InputMoveForPacMan.h"

namespace PacMan
{
    namespace Logic
    {
        char InputPacManMove::get_char () const
        {
            char choice;

            m_in >> choice;

            return choice;
        }

        void InputPacManMove::initialize ()
        {
            m_char_to_heading [ Input_PacMan_Up ] = Heading_Up;
            m_char_to_heading [ Input_PacMan_Down ] = Heading_Down;
            m_char_to_heading [ Input_PacMan_Left ] = Heading_Left;
            m_char_to_heading [ Input_PacMan_Right ] = Heading_Right;
        }

        Heading InputPacManMove::convert_char_to_heading ( const char input ) const
        {
            auto pair = m_char_to_heading.find ( input );

            Heading heading = Heading_Unknown;

            if ( pair != m_char_to_heading.end() )
            {
                heading = pair->second;
            }

            return heading;
        }

        Heading InputPacManMove::get_heading () const
        {
            Heading heading;

            do
            {
                m_out << "Move? (w,s,a,d) ";

                char input = get_char();

                heading = convert_char_to_heading ( input );
            }
            while ( heading == Heading_Unknown );

            return heading;
        }
    };
};
