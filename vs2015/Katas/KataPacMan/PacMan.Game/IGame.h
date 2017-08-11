#pragma once

#include "IPlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        class IGame
        {
        public:
            virtual ~IGame() = default;

            virtual void run() const = 0;
        };

        typedef std::shared_ptr<IGame> IGame_Ptr;
    };
};