#include "stdafx.h"
#include "ObjectsMoveValidator.h"
#include "IMovingObjectsRepository.h"
#include <iostream>

using namespace PacMan::Logic;

void ObjectsMoveValidator::initialize ( 
    const IMovingObjectsRepository_Ptr& repository )
{
    m_repository = repository;
}

void ObjectsMoveValidator::validate_moves ()
{
    auto all = m_repository->get_all();
    auto all_other = m_repository->get_all();

    for (auto info : (*all))
    {
        for (auto other_info : (*all_other))
        {
            if (info == other_info)
            {
                continue;
            }

            std::cout
                << "Validating ["
                << "("
                << info->playing_field_object_type
                << ") "
                << info->to_row
                << ", "
                << info->to_column
                << "] with ["
                << "("
                << other_info->playing_field_object_type
                << ") "
                << other_info->to_row
                << ", "
                << other_info->to_column
                << "]\n";

            if (info->to_row == other_info->to_row &&
                info->to_column == other_info->to_column)
            {
                if (info->playing_field_object_type == PlayingFieldObjectType_PacMan)
                {
                    std::cout
                        << "GAME OVER!\n"
                        << "PacMan got eaten by a Monster!\n";

                    return; // todo set status
                }
            }

            // todo add move to validated moves
        }
    }
}
