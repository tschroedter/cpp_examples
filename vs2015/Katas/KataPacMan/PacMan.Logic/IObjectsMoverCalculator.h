#pragma once

#include <memory>
#include "IPlayingField.h"
#include "IMovingObjectsRepository.h"

namespace PacMan
{
    namespace Logic
    {
        class IObjectsMoverCalculator
        {
        public:
            virtual ~IObjectsMoverCalculator () = default;

            virtual void initialize (
                const IPlayingField_Ptr playing_field,
                const IMovingObjectsRepository_Ptr repository ) = 0;

            virtual void calculate () const = 0;
        };

        typedef std::shared_ptr<IObjectsMoverCalculator> IObjectsMoverCalculator_Ptr;
    };
};
