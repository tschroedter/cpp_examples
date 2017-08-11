#include "stdafx.h"
#include "Game.h"
#include "IPlayingField.h"
#include "IDisplayPlayingField.h"
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
            // todo
            m_monster->set_heading(Heading_Down);

            m_playing_field->initialize(
                                        size_t(3),
                                        size_t(3));

            m_playing_field->put_object_at(
                                           m_pac_man,
                                           size_t(1),
                                           size_t(1));

            m_playing_field->put_object_at(
                                           m_monster,
                                           size_t(0),
                                           size_t(0));

            m_display->initialize(m_playing_field);
            m_input->initialize();
            m_game_timer->initialize(m_playing_field);

            auto status = m_game_timer->get_status();

            while (ValidationStatus_PacMan_Death != status)
            {
                m_display->print();
                Heading new_heading = m_input->get_heading();
                m_pac_man->set_heading(new_heading);
                m_game_timer->tick();
                status = m_game_timer->get_status();
            }

            if (ValidationStatus_PacMan_Death == status)
            {
                std::cout
                    << "GAME OVER!\n"
                    << "PacMan got eaten by a Monster!\n";
            }
        }
    }
}
