#include "stdafx.h"
#include "Game.h"
#include "IPlayingField.h"
#include "IPacMan.h"
#include "IDisplayPlayingField.h"
#include "IMonster.h"
#include "IInputPacManMove.h"
#include "IGameTimer.h"
#include <iostream>

namespace PacMan
{
    namespace Match
    {
        void Game::run () const
        {
            using namespace Logic;
            IPlayingField_Ptr playing_field = m_container->resolve<IPlayingField>();
            playing_field->initialize(
                                      size_t(3),
                                      size_t(3));

            IPacMan_Ptr pac_man =
                m_container->resolve<IPacMan>();

            playing_field->put_object_at(
                                         pac_man,
                                         size_t(1),
                                         size_t(1));

            IMonster_Ptr monster =
                m_container->resolve<IMonster>();
            monster->set_heading(Heading_Down);

            playing_field->put_object_at(
                                         monster,
                                         size_t(0),
                                         size_t(0));

            View::IDisplayPlayingField_Ptr display =
                m_container->resolve<View::IDisplayPlayingField>();

            display->initialize(playing_field);

            display->print();

            IInputPacManMove_Ptr input_pac_man_move =
                m_container->resolve<IInputPacManMove>();
            input_pac_man_move->initialize();
            Heading new_heading = input_pac_man_move->get_heading();
            pac_man->set_heading(new_heading);

            IObjectMover_Ptr object_mover =
                m_container->resolve<IObjectMover>();
            object_mover->initialize(playing_field);

            IObjectsMover_Ptr objects_mover =
                m_container->resolve<IObjectsMover>();
            objects_mover->initialize(playing_field);

            IGameTimer_Ptr game_timer =
                m_container->resolve<IGameTimer>();
            game_timer->initialize(playing_field,
                                   object_mover,
                                   objects_mover);

            game_timer->tick();
            auto status = game_timer->get_status();

            if (ValidationStatus_PacMan_Death == status)
            {
                std::cout
                    << "GAME OVER!\n"
                    << "PacMan got eaten by a Monster!\n";
            }

            display->print();
        }
    }
}
