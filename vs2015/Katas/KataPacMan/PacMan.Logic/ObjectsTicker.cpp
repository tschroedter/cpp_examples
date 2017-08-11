#include "stdafx.h"
#include "ObjectsTicker.h"

using namespace PacMan::Logic;

void ObjectsTicker::initialize (
    const IPlayingField_Ptr& playing_field )
{
    m_playing_field = playing_field;
}

void ObjectsTicker::tick () const
{
    size_t number_of_rows = m_playing_field->get_rows();
    size_t number_of_columns = m_playing_field->get_columns();

    for (size_t row = 0; row < number_of_rows; row++)
    {
        for (size_t column = 0; column < number_of_columns; column++)
        {
            auto object =
                m_playing_field->get_object_at(
                                               row,
                                               column);

            object->tick();
        }
    }
}
