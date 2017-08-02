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
            ObjectsMoveValidator();
            ~ObjectsMoveValidator() = default;

            void initialize(const IMovingObjectsRepository_Ptr& repository) override;
            void validate_moves() override;
            ValidationStatus get_status() const override;

        private:
            IMovingObjectsRepository_Ptr m_repository;
            ValidationStatus m_status;
        };
    }
}
