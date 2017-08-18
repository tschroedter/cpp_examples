#pragma once
#include "IDisplayWall.h"

namespace PacMan
{
    namespace View
    {
        class DisplayWall
            : public IDisplayWall
        {
        private:
            Logic::IPlayingFieldObject_Ptr m_object = nullptr;
            const DisplayObjectType m_type = DisplayObjectType_Wall;
            const std::string m_to_string = "# ";

        public:
            ~DisplayWall ()
            {
            }

            DisplayObjectType get_type () const override;

            void initialize ( const Logic::IPlayingFieldObject_Ptr object ) override;

            std::string to_string () const override;
        };
    };
};
