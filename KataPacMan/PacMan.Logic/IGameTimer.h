#pragma once

#include <memory>
#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        class IGameTimer
        {
        public:
            virtual ~IGameTimer() = default;

            virtual void initialize(const IPlayingField_Ptr playing_field) = 0;
            virtual void tick() const = 0;
        };

        typedef std::shared_ptr<IGameTimer> IGameTimer_Ptr;
    };
};
