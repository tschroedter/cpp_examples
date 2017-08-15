#pragma once
#include "IObjectsMoverCalculator.h"
#include "IMovingObjectsRepository.h"
#include "IObjectMoveCalculator.h"
#include <Hypodermic/FactoryWrapper.h>

namespace PacMan
{
    namespace Logic
    {
        class ObjectsMoverCalculator
            : public IObjectsMoverCalculator
        {
        public:
            ObjectsMoverCalculator (
                const Hypodermic::FactoryWrapper<IMoveObjectInformation>& factory_wrapper,
                const IObjectMoveCalculator_Ptr calculator );

            ~ObjectsMoverCalculator () = default;

            void initialize (
                const IPlayingField_Ptr playing_field,
                const IMovingObjectsRepository_Ptr repository ) override;

            void calculate () const override;

            IMoveObjectInformation_Ptr create_info (
                Row row,
                Column column,
                IPlayingFieldObject_Ptr object ) const;

        private:
            std::function<std::shared_ptr<IMoveObjectInformation> ()> m_factory;
            IPlayingField_Ptr m_playing_field;
            IObjectMoveCalculator_Ptr m_calculator;
            IMovingObjectsRepository_Ptr m_repository;
        };
    }
}
