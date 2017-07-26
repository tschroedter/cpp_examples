#pragma once
#include "IDisplayMax.h"

namespace PacMan
{
    namespace View
    {
        class DisplayMax
            : public IDisplayMax
        {
        private:
            Logic::IPlayingFieldObject_Ptr m_object = nullptr;
            const DisplayObjectType m_type = DisplayObjectType_Max;
            const std::string m_to_string = "MA";

        public:
            ~DisplayMax ()
            {
            }

            DisplayObjectType get_type () const override;
            void initialize ( const Logic::IPlayingFieldObject_Ptr object ) override;
            std::string to_string () override;
        };
    };
};
