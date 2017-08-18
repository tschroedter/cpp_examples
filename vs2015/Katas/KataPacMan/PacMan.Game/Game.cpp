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
        using namespace Logic;

        void Game::create_walls () const
        {
            auto rows = m_playing_field->get_rows() - Row(1);
            auto columns = m_playing_field->get_columns() - Column(1);

            for (Column j = 1; j < columns; j++)
            {
                if (j % 3 != 0)
                {
                    continue;
                }

                for (Row i = 1; i < rows; i++)
                {
                    if (i % 3 == 0)
                    {
                        continue;
                    }

                    IWall_Ptr one = m_factory();

                    m_playing_field->put_object_at(
                        one,
                        Row(i),
                        Column(j));
                }
            }
        }

        void Game::run () const
        {
            m_monster->set_heading(Heading_Down);

            m_playing_field->initialize(
                                        Row(10),
                                        Column(10));

            create_walls();

            auto pacman_row = m_playing_field->get_rows() - Row(1);
            auto pacman_column = m_playing_field->get_columns() - Column(1);

            m_playing_field->put_object_at(
                                           m_pac_man,
                                           pacman_row,
                                           pacman_column);

            m_playing_field->put_object_at(
                                           m_monster,
                                           Row(0),
                                           Column(0));

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

            m_display->print();

            if (ValidationStatus_PacMan_Death == status)
            {
                std::cout
                    << "GAME OVER!\n"
                    << "PacMan got eaten by a Monster!\n";
            }
        }
    }
}
