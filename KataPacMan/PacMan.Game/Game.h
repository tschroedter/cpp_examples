#pragma once

#include "IIOCContainerBuilder.h"

namespace PacMan
{
    namespace Match
    {
        class Game
        {
        private:
            Container_Ptr m_container;

        public:
            Game ( Container_Ptr container )
                : m_container ( container )
            {
            }

            ~Game ()
            {
            }

            void run () const;
        };
    };
};
