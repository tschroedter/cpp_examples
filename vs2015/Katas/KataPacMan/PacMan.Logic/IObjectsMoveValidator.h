#pragma once

#include <memory>
#include "IMovingObjectsRepository.h"

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
        };

        typedef std::shared_ptr<IObjectsMoveValidator> IObjectsMoveValidator_Ptr;
    };
};
