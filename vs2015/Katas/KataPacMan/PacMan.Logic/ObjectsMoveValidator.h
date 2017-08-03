#pragma once
#include "IObjectsMoveValidator.h"
#include "IMovingObjectsRepository.h"

namespace PacMan
{
    namespace Logic
    {
        class ObjectsMoveValidator // todo testing
            : public IObjectsMoveValidator
        {
        public:
            ObjectsMoveValidator ();
            ~ObjectsMoveValidator () = default;

            void initialize ( const IMovingObjectsRepository_Ptr& repository ) override;
            ValidationStatus get_status () const override;
            void validate_moves () override;

        private:
            IMovingObjectsRepository_Ptr m_repository;
            ValidationStatus m_status;

            ValidationStatus calculate_status_depending_on_move (
                const IMoveObjectInformation_Ptr info ) const;
        };
    }
}
