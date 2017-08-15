#pragma once
#include "IDisplayDot.h"

namespace PacMan
{
    namespace View
    {
        class DisplayDot
            : public IDisplayDot
        {
        private:
            Logic::IPlayingFieldObject_Ptr m_object = nullptr;
            const DisplayObjectType m_type = DisplayObjectType_Dot;
            const std::string m_to_string = ". ";

        public:
            ~DisplayDot ()
            {
            }

            DisplayObjectType get_type () const override;

            void initialize ( const Logic::IPlayingFieldObject_Ptr object ) override;

            std::string to_string () const override;
        };
    };
};
