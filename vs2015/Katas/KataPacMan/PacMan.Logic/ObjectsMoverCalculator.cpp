#include "stdafx.h"
#include "ObjectsMoverCalculator.h"
#include "MoveObjectInformation.h"

using namespace PacMan::Logic;

ObjectsMoverCalculator::ObjectsMoverCalculator (
    const IObjectMoveCalculator_Ptr calculator )
    : m_calculator(calculator)
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

    size_t number_of_rows = m_playing_field->get_rows();
    size_t number_of_columns = m_playing_field->get_columns();

    for (size_t row = 0; row < number_of_rows; row++)
    {
        for (size_t column = 0; column < number_of_columns; column++)
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

IMoveObjectInformation_Ptr ObjectsMoverCalculator::create_info (
    size_t row,
    size_t column,
    IPlayingFieldObject_Ptr object ) const
{
    Heading heading = object->get_heading();

    m_calculator->calculate(row,
                            column,
                            heading);

    auto p_info = new MoveObjectInformation{}; // todo use factory
    IMoveObjectInformation_Ptr shared(p_info);

    shared->from_row = row;
    shared->from_column = column;
    shared->to_row = m_calculator->to_row;
    shared->to_column = m_calculator->to_column;
    shared->playing_field_object_type = object->get_type();

    return shared;
}
