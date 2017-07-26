#pragma once

#include "Heading.h"
#include "IDirection.h"

namespace PacMan
{
    namespace Logic
    {
        class Direction
            : public IDirection
        {
        private:
            Heading m_heading = Heading_Up;

        public:
            ~Direction ()
            {
            }

            Heading get_heading () const override;
            void set_heading ( Heading heading ) override;
        };
    };
};
