#pragma once

#include <memory>
#include "IMovingObjectsRepository.h"
#include "ValidationStatus.h"

namespace PacMan
{
    namespace Logic
    {
        class IObjectsMoveValidator
        {
        public:
            virtual ~IObjectsMoveValidator() = default;

            virtual void initialize(const IMovingObjectsRepository_Ptr& repository) = 0;
            virtual void validate_moves () = 0;
            virtual ValidationStatus get_status() const = 0;
        };

        typedef std::shared_ptr<IObjectsMoveValidator> IObjectsMoveValidator_Ptr;
    };
};
