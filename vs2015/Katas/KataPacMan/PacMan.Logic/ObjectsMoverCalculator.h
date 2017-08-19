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
            bool is_target_a_wall ( const Row row, const Column column ) const;

            IMoveObjectInformation_Ptr create_info (
                Row row,
                Column column,
                IPlayingFieldObject_Ptr object ) const;

        private:
            std::function<std::shared_ptr<IMoveObjectInformation>  ()> m_factory;
            IPlayingField_Ptr m_playing_field;
            IObjectMoveCalculator_Ptr m_calculator;
            IMovingObjectsRepository_Ptr m_repository;

            Row calculate_to_row (
                const Row row,
                const Column column,
                const Row to_row,
                const Column to_column ) const;
            Row calculate_to_column (
                const Row row,
                const Column column,
                const Row to_row,
                const Column to_column ) const;
            IMoveObjectInformation_Ptr ObjectsMoverCalculator::create_info_instance (
                IPlayingFieldObject_Ptr object,
                Row row,
                Column column,
                Row to_row,
                Column to_column ) const;
        };
    }
}
