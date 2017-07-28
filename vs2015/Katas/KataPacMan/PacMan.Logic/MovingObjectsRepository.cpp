#include "stdafx.h"
#include "MovingObjectsRepository.h"
#include <functional>
#include <iostream>

namespace PacMan
{
    namespace Logic
    {
        MovingObjectsRepository::MovingObjectsRepository (
            MovingObjectsInformationVector_Ptr vector )
            : m_informations(vector)
        {
        }

        void MovingObjectsRepository::add (
            const IMoveObjectInformation_Ptr information )
        {
            m_informations->push_back(information);
        }

        void MovingObjectsRepository::clear ()
        {
            m_informations->clear();
        }

        MovingObjectsInformationVector_Ptr MovingObjectsRepository::get_all_with_filter (
            std::function<bool  ( IMoveObjectInformation_Ptr& )> func ) const
        {
            MovingObjectsInformationVector* p_vector = new MovingObjectsInformationVector();

            for (auto iter = m_informations->begin(); iter != m_informations->end();
                 ++iter)
            {
                IMoveObjectInformation_Ptr info = (*iter);

                if (func(info))
                {
                    p_vector->push_back(info);
                }
            }

            auto all = std::shared_ptr<MovingObjectsInformationVector>(p_vector);

            return (all);
        }

        MovingObjectsInformationVector_Ptr MovingObjectsRepository::get_all () const
        {
            auto lambda =
                [](const IMoveObjectInformation_Ptr& ptr)
            {
                return true;
            };

            auto all = get_all_with_filter(lambda);

            return (all);
        }

        MovingObjectsInformationVector_Ptr MovingObjectsRepository::get_all_of_type ( PlayingFieldObjectType type ) const
        {
            auto lambda =
                [type](const IMoveObjectInformation_Ptr& ptr)
            {
                return ptr->playing_field_object_type == type;
            };

            auto all = get_all_with_filter(lambda);

            return (all);
        }

        std::ostream& MovingObjectsRepository::print_moves ( std::ostream& out ) const
        { // todo testing
            int counter = 0;
            auto all = get_all();

            for (auto iter = all->begin(); iter != all->end();
                 ++iter)
            {
                IMoveObjectInformation_Ptr info = (*iter);

                out << "[" << counter << "]"
                    << " (" << info->from_row
                    << " , " << info->from_column
                    << ") --> (" << info->to_row
                    << ", " << info->to_column
                    << ") Type: " << info->playing_field_object_type
                    << "\n";

                counter++;
            }

            return out;
        }
    }
}
