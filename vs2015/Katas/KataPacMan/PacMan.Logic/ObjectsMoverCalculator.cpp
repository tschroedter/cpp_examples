#include "stdafx.h"
#include "ObjectsMoverCalculator.h"
#include "MoveObjectInformation.h"
#include "IToRowAnToColumnCalculator.h"

using namespace PacMan::Logic;

ObjectsMoverCalculator::ObjectsMoverCalculator (
    const Hypodermic::FactoryWrapper<IMoveObjectInformation>& factory_wrapper,
    const IToRowAnToColumnCalculator_Ptr calculator )
    : m_factory(factory_wrapper.getFactory()),
      m_calculator{ calculator }
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
{
    Heading heading = object->get_heading();

    m_calculator->from_row = row;
    m_calculator->from_column = column;
    m_calculator->heading = heading;
    m_calculator->caclulate();

    auto shared = create_info_instance(
                                       object,
                                       row,
                                       column,
                                       m_calculator->to_row,
                                       m_calculator->to_column);

    return shared;
}
