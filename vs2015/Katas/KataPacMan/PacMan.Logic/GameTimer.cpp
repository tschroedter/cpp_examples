#include "stdafx.h"
#include "GameTimer.h"

namespace PacMan
{
    namespace Logic
    {
        void GameTimer::initialize (
            const IPlayingField_Ptr playing_field,
            const IObjectMover_Ptr object_mover)
        {
            m_playing_field = playing_field;
            m_object_mover = object_mover;
        }

        void GameTimer::tick ()
        {
            size_t number_of_rows = m_playing_field->get_rows();
            size_t number_of_columns = m_playing_field->get_columns();

            for (size_t row = 0; row < number_of_rows; row++)
            {
                for (size_t column = 0; column < number_of_columns; column++)
                {
                    // todo move object only once
                    m_object_mover->move_object(row, column);
                }
            }
        }
    };
};
