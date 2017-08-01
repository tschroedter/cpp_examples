#pragma once
#include "IObjectsMoveValidator.h"
#include "IMovingObjectsRepository.h"

namespace PacMan
{
    namespace Logic
    {
        class ObjectsMoveValidator  // todo testing
            : public IObjectsMoveValidator
        {
        public:
            ObjectsMoveValidator() = default;
            ~ObjectsMoveValidator() = default;

            void initialize(const IMovingObjectsRepository_Ptr& repository) override;
            void validate_moves() override;

        private:
            IMovingObjectsRepository_Ptr m_repository;
        };
    }
}
