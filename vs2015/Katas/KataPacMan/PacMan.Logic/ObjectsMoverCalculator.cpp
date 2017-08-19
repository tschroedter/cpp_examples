#include "stdafx.h"
#include "ObjectsMoverCalculator.h"
#include "MoveObjectInformation.h"

using namespace PacMan::Logic;

ObjectsMoverCalculator::ObjectsMoverCalculator (
    const Hypodermic::FactoryWrapper<IMoveObjectInformation>& factory_wrapper,
    const IObjectMoveCalculator_Ptr calculator )
    : m_factory(factory_wrapper.getFactory()),
      m_calculator(calculator)
{
}

void ObjectsMoverCalculator::initialize (
    const IPlayingField_Ptr playing_field,
    const IMovingObjectsRepository_Ptr repository )
{
    m_playing_field = playing_field;
    m_repository = repository;
    m_calculator->initialize(playing_field);
}

void ObjectsMoverCalculator::calculate () const
{
    m_repository->clear();

    Row number_of_rows = m_playing_field->get_rows();
    Column number_of_columns = m_playing_field->get_columns();

    for (Row row = 0; row < number_of_rows; row++)
    {
        for (Column column = 0; column < number_of_columns; column++)
        {
            auto object = m_playing_field->get_object_at(row,
                                                         column);

            if (!object->is_moving())
            {
                continue;
            }

            auto info = create_info(row, column, object);

            m_repository->add(info);
        }
    }
}

bool ObjectsMoverCalculator::is_target_a_wall (
    const Row row,
    const Column column ) const
{
    auto type =
        m_playing_field->get_object_type_at(
                                            row,
                                            column);

    return PlayingFieldObjectType_Wall == type;
}

Row ObjectsMoverCalculator::calculate_to_row (
    const Row row,
    const Column column,
    const Row to_row,
    const Column to_column ) const
{
    if (is_target_a_wall(to_row, to_column))
    {
        return row;
    }

    return to_row;
}

Row ObjectsMoverCalculator::calculate_to_column (
    const Row row,
    const Column column,
    const Row to_row,
    const Column to_column ) const
{
    if (is_target_a_wall(to_row, to_column))
    {
        return column;
    }

    return to_column;
}

IMoveObjectInformation_Ptr ObjectsMoverCalculator::create_info_instance (
    IPlayingFieldObject_Ptr object,
    Row row,
    Column column,
    Row to_row,
    Column to_column ) const
{
    auto p_info = m_factory();
    IMoveObjectInformation_Ptr shared(p_info);

    shared->from_row = row;
    shared->from_column = column;
    shared->to_row = to_row;
    shared->to_column = to_column;
    shared->playing_field_object_type = object->get_type();

    return shared;
}

IMoveObjectInformation_Ptr ObjectsMoverCalculator::create_info (
    Row row,
    Column column,
    IPlayingFieldObject_Ptr object ) const
{ // todo move calc and creation into other class
    Heading heading = object->get_heading();

    m_calculator->calculate(row,
                            column,
                            heading);

    Row to_row = calculate_to_row(
                                  row,
                                  column,
                                  m_calculator->to_row,
                                  m_calculator->to_column);

    Column to_column = calculate_to_column(row,
                                           column,
                                           m_calculator->to_row,
                                           m_calculator->to_column);

    auto shared = create_info_instance(
                                       object,
                                       row,
                                       column,
                                       to_row,
                                       to_column);

    return shared;
}
