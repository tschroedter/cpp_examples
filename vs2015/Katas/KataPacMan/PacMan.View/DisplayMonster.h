#pragma once
#include "IDisplayPacMan.h"
#include "IDisplayMonster.h"

namespace PacMan
{
    namespace View
    {
        class DisplayMonster
            : public IDisplayMonster
        {
        private:
            Logic::IPlayingFieldObject_Ptr m_object = nullptr;
            const DisplayObjectType m_type = DisplayObjectType_Monster;
            const std::string m_to_string = "M ";

        public:
            ~DisplayMonster ()
            {
            }

            DisplayObjectType get_type () const override;
            void initialize ( const Logic::IPlayingFieldObject_Ptr object ) override;
            std::string to_string () const override;
        };
    };
};
