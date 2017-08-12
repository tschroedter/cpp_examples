#include "stdafx.h"
#include "MonsterHeadingCalculator.h"

using namespace PacMan::Logic;

int MonsterHeadingCalculator::calculate_delta_row () const
{
    int delta = static_cast<int>(monster_row) - static_cast<int>(pacman_row);

    return delta;
}

int MonsterHeadingCalculator::calculate_delta_column () const
{
    int delta = static_cast<int>(monster_column) - static_cast<int>(pacman_column);

    return delta;
}

void MonsterHeadingCalculator::calculate ()
{
    int delta_row = calculate_delta_row();

    if (delta_row < 0)
    {
        m_heading = Heading_Down;

        return;
    }

    if (delta_row > 0)
    {
        m_heading = Heading_Up;

        return;
    }

    int delta_column = calculate_delta_column();

    if (delta_column < 0)
    {
        m_heading = Heading_Right;

        return;
    }

    if (delta_column > 0)
    {
        m_heading = Heading_Left;

        return;
    }

    m_heading = Heading_Unknown;
}

Heading MonsterHeadingCalculator::get_heading () const
{
    return m_heading;
}
