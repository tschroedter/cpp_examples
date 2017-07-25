#include "stdafx.h"
#include "MovingObjectsRepository.h"

namespace PacMan
{
    namespace Logic
    {
        MovingObjectsRepository::MovingObjectsRepository (
            MovingObjectsInformationVector_Ptr vector)
            : m_informations(vector)
        {
        }

        void MovingObjectsRepository::add ( 
            const IMoveObjectInformation_Ptr information)
        {
            m_informations->push_back(information);
        }

        void MovingObjectsRepository::clear ()
        {
            m_informations->clear();
        }

        MovingObjectsInformationVector_Ptr MovingObjectsRepository::get_all ()
        {
            MovingObjectsInformationVector* p_vector = new MovingObjectsInformationVector();

            for (auto iter = m_informations->begin(); iter != m_informations->end();
                iter++)
            {
                IMoveObjectInformation_Ptr info = (*iter);

                p_vector->push_back(info);
            }

            auto all = std::shared_ptr<MovingObjectsInformationVector>(p_vector);

            return (all);
        }
    }
}
