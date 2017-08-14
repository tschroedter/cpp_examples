#include "stdafx.h"
#include "GameTimer.h"
#include "IObjectsMover.h"
#include <iostream>

namespace PacMan
{
    namespace Logic
    {
        void GameTimer::initialize (
            const IPlayingField_Ptr playing_field )
        {
            m_playing_field = playing_field;
            m_monster_updater->initialize(playing_field);
            m_objects_mover->initialize(playing_field);
            m_objects_ticker->initialize(playing_field);
        }

        void GameTimer::tick ()
        {
            m_monster_updater->update();
            m_objects_ticker->tick();
            m_objects_mover->calculate();
            m_objects_mover->print_moves(std::cout);
            m_objects_mover->move_objects();
        }

        ValidationStatus GameTimer::get_status () const
        {
            return m_objects_mover->get_status();
        }
    };
};
