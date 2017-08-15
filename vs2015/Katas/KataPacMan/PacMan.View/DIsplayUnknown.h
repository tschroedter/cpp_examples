#pragma once
#include "IDisplayPacMan.h"
#include "IDisplayUnknown.h"

namespace PacMan
{
    namespace View
    {
        class DisplayUnknown
            : public IDisplayUnknown
        {
        private:
            Logic::IPlayingFieldObject_Ptr m_object = nullptr;
            const DisplayObjectType m_type = DisplayObjectType_Dot;
            const std::string m_to_string = "? ";

        public:
            ~DisplayUnknown ()
            {
            }

            DisplayObjectType get_type () const override;
            void initialize ( const Logic::IPlayingFieldObject_Ptr object ) override;
            std::string to_string () const override;
        };
    };
};
