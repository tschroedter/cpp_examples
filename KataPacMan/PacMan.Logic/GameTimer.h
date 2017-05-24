#pragma once

#include "IGameTimer.h"
#include "IPlayingField.h"

namespace PacMan
{
    namespace Logic
    {
        class GameTimer
            : public IGameTimer
        {
        private:
            IPlayingField_Ptr m_playing_field;

        public:
            GameTimer()
                : m_playing_field ( nullptr )
            {
            }

            ~GameTimer()
            {
            }

            void initialize(const IPlayingField_Ptr playing_field) override;
            void tick() const override;
        };
    };
};
