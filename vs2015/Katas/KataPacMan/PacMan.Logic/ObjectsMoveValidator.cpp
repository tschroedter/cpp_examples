﻿#include "stdafx.h"
#include "ObjectsMoveValidator.h"
#include "IMovingObjectsRepository.h"

using namespace PacMan::Logic;

ObjectsMoveValidator::ObjectsMoveValidator ()
{
    m_status = ValidationStatus_Unknown;
}

void ObjectsMoveValidator::initialize (
    const IMovingObjectsRepository_Ptr& repository )
{
    m_repository = repository;
}

ValidationStatus ObjectsMoveValidator::calculate_status_depending_on_move (
    const IMoveObjectInformation_Ptr info ) const
{
    auto all_other = m_repository->get_all();

    for (auto other_info : (*all_other))
    {
        if (info == other_info)
        {
            continue;
        }

        if (info->to_row == other_info->to_row &&
            info->to_column == other_info->to_column)
        {
            if (info->playing_field_object_type == PlayingFieldObjectType_PacMan &&
                other_info->playing_field_object_type ==
                PlayingFieldObjectType_Monster)
            {
                return ValidationStatus_PacMan_Death;
            }
        }
    }
    return ValidationStatus_PacMan_ALive;
}

void ObjectsMoveValidator::validate_moves ()
{
    m_status = ValidationStatus_PacMan_ALive;

    auto all = m_repository->get_all();

    for (IMoveObjectInformation_Ptr info : (*all))
    {
        m_status = calculate_status_depending_on_move(info);

        if (ValidationStatus_PacMan_Death == m_status)
        {
            return;
        }
    }
}

ValidationStatus ObjectsMoveValidator::get_status () const
{
    return m_status;
}
