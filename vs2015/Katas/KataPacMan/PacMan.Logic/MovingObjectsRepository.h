#pragma once
#include "IMovingObjectsRepository.h"
#include "IMoveObjectInformation.h"

namespace PacMan
{
    namespace Logic
    {
        class MovingObjectsRepository   // todo testing
            : public IMovingObjectsRepository
        {
        public:
            MovingObjectsRepository(
                MovingObjectsInformationVector_Ptr vector);
            ~MovingObjectsRepository() = default;

            void add(const IMoveObjectInformation_Ptr information) override;
            void clear() override;
            MovingObjectsInformationVector_Ptr get_all() override;

        private:
            MovingObjectsInformationVector_Ptr m_informations;
        };
    }
}
