#pragma once

#include <iostream>
#include "Heading.h"
#include "IInputPacManMove.h"
#include <map>

namespace PacMan
{
    namespace Logic
    {
        class InputPacManMove
            : public IInputPacManMove
        {
        private:
            std::istream& m_in;
            std::ostream& m_out;
            char get_char () const;

            const char Input_PacMan_Up = 'w';
            const char Input_PacMan_Down = 's';
            const char Input_PacMan_Left = 'a';
            const char Input_PacMan_Right = 'd';

            std::map<char, Heading> m_char_to_heading;

            Heading convert_char_to_heading ( const char input ) const;

        public:
            InputPacManMove (
                std::ostream& out = std::cout,
                std::istream& in = std::cin )
                : m_in(in)
                  , m_out(out)
            {
            }

            ~InputPacManMove ()
            {
            }

            void initialize () override;
            Heading get_heading () const override;
        };
    };
};
