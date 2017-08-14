#include "stdafx.h"
#include "Locator.h"
#include <vector>
#include "LocatorInformation.h"

using namespace PacMan::Logic;

LocatorInformationVector_Ptr Locator::get_all_with_filter (
    std::function<bool  ( IPlayingFieldObject_Ptr& )> func ) const
{
    LocatorInformationVector* p_vector = new LocatorInformationVector();

    Row number_of_rows = m_playing_field->get_rows();
    Column number_of_columns = m_playing_field->get_columns();

    for (Row row = 0; row < number_of_rows; row++)
    {
        for (Column column = 0; column < number_of_columns; column++)
        {
            auto object = m_playing_field->get_object_at(row,
                                                         column);

            if (func(object))
            {
                LocatorInformation* p_info = new LocatorInformation{};
                p_info->object = object;
                p_info->row = row;
                p_info->column = column;

                ILocatorInformation_Ptr info(p_info);

                p_vector->push_back(info);
            }
        }
    }

    auto all = std::shared_ptr<LocatorInformationVector>(p_vector);

    return (all);
}

void Locator::initialize (
    const IPlayingField_Ptr& playing_field )
{
    m_playing_field = playing_field;
}

LocatorInformationVector_Ptr Locator::get_all () const
{
    auto lambda =
        [](const IPlayingFieldObject_Ptr& ptr)
    {
        return true;
    };

    auto all = get_all_with_filter(lambda);

    return (all);
}

LocatorInformationVector_Ptr Locator::get_all_of_type (
    PlayingFieldObjectType type ) const
{
    auto lambda =
        [type](const IPlayingFieldObject_Ptr& ptr)
    {
        return ptr->get_type() == type;
    };

    auto all = get_all_with_filter(lambda);

    return (all);
}
