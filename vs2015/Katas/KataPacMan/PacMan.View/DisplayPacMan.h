#pragma once
#include "IDisplayPacMan.h"
#include <map>
#include "Heading.h"
#include "IPacMan.h"

namespace PacMan
{
    namespace View
    {
        class DisplayPacMan
            : public IDisplayPacMan
        {
        private:
            Logic::IPlayingFieldObject_Ptr m_object = nullptr;
            const DisplayObjectType m_type = DisplayObjectType_PacMan;
            const std::string m_to_string = "  ";

            const std::string PacMan_Unknown = "UN";
            const std::string PacMan_Up = "\\/";
            const std::string PacMan_Down = "/\\";
            const std::string PacMan_Left = " >";
            const std::string PacMan_Right = "< ";
            const std::string PacMan_Max = "MA";

            std::map<Logic::Heading, std::string> m_heading_to_string;

        public:
            ~DisplayPacMan ()
            {
            }

            DisplayObjectType get_type () const override;
            void initialize ( const Logic::IPlayingFieldObject_Ptr object ) override;
            std::string to_string () override;
        };
    };
};
