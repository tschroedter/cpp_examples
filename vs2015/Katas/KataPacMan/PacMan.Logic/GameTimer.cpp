#include "stdafx.h"
#include "GameTimer.h"
#include "IObjectsMover.h"
#include <iostream>

namespace PacMan
{
    namespace Logic
    {
        void GameTimer::initialize (
            const IPlayingField_Ptr playing_field,
            const IObjectMover_Ptr object_mover,
            const IObjectsMover_Ptr objects_mover )
        {
            m_playing_field = playing_field;
            m_object_mover = object_mover;
            m_objects_mover = objects_mover;
        }

        void GameTimer::tick ()
        {
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
