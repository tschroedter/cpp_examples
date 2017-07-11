#pragma once

#include "IGameTimer.h"
#include "IPlayingField.h"
#include "IObjectMover.h"

namespace PacMan
{
    namespace Logic
    {
        class GameTimer
            : public IGameTimer
        {
        private:
            IPlayingField_Ptr m_playing_field;
            IObjectMover_Ptr m_object_mover;

        public:
            GameTimer()
                : m_playing_field ( nullptr )
                , m_object_mover(nullptr)
            {
            }

            ~GameTimer()
            {
            }

            void initialize(
                const IPlayingField_Ptr playing_field,
                const IObjectMover_Ptr object_mover) override; // todo move into constructor

            void tick() override;
        };
    };
};
