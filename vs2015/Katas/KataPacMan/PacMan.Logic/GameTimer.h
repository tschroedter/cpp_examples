#pragma once

#include "IGameTimer.h"
#include "IPlayingField.h"
#include "IObjectMover.h"
#include "IObjectsMover.h"

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
            IObjectsMover_Ptr m_objects_mover;

        public:
            GameTimer ()
                : m_playing_field(nullptr)
                  , m_object_mover(nullptr)
                  , m_objects_mover(nullptr)
            {
            }

            ~GameTimer ()
            {
            }

            void initialize (
                const IPlayingField_Ptr playing_field,
                const IObjectMover_Ptr object_mover,
                const IObjectsMover_Ptr objects_mover ) override; // todo move into constructor

            void tick () override;
        };
    };
};
