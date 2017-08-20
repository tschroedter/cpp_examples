#include "stdafx.h"
#include "ToRowAnToColumnCalculator.h"

using namespace PacMan::Logic;

bool ToRowAnToColumnCalculator::is_target_a_wall (
    const Row row,
    const Column column ) const
{
    auto type =
        m_playing_field->get_object_type_at(
                                            row,
                                            column);

    return PlayingFieldObjectType_Wall == type;
}

void ToRowAnToColumnCalculator::initialize (
    const IPlayingField_Ptr playing_field )
{
    m_playing_field = playing_field;
    m_calculator->initialize(playing_field);
}

void ToRowAnToColumnCalculator::caclulate ()
{
    m_calculator->calculate(from_row,
                            from_column,
                            heading);

    to_row = m_calculator->to_row;
    to_column = m_calculator->to_column;

    if (is_target_a_wall(to_row, to_column))
    {
        to_row = from_row;
        to_column = from_column;
    }
}
