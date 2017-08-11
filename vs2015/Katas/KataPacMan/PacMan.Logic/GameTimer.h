#pragma once

#include "IGameTimer.h"
#include "IPlayingField.h"
#include "IObjectMover.h"
#include "IObjectsMover.h"
#include "IObjectsTicker.h"

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
            IObjectsTicker_Ptr m_objects_ticker;

        public:
            GameTimer (
                IObjectsMover_Ptr objects_mover,
                IObjectsTicker_Ptr objects_ticker)
                : m_playing_field(nullptr),
                  m_objects_mover(objects_mover),
                  m_objects_ticker(objects_ticker)
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
