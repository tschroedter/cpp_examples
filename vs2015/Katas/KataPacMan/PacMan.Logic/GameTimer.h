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
            IObjectsMover_Ptr m_objects_mover;

        public:
            GameTimer (
                IObjectsMover_Ptr objects_mover )
                : m_playing_field(nullptr)
                  , m_objects_mover(objects_mover)
            {
            }

            ~GameTimer ()
            {
            }

            void initialize (
                const IPlayingField_Ptr playing_field ) override;

            void tick () override;
            ValidationStatus get_status () const override; // todo testing
        };
    };
};
