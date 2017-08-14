#pragma once

#include "IPlayingField.h"
#include "IPlayingFieldValidator.h"
#include "IDot.h"
#include "Hypodermic/FactoryWrapper.h"

namespace PacMan
{
    namespace Logic
    {
        class PlayingField
            : public IPlayingField
        {
        private:
            IPlayingFieldValidator_Ptr m_validator;
            IPlayingFieldObject_Ptr** m_field;
            Row m_rows;
            Column m_columns;
            std::function<std::shared_ptr<IDot>  ()> m_factory;

            IPlayingFieldObject_Ptr** create_field (
                const Row rows,
                const Column columns ) const;

        public:
            PlayingField (
                const Hypodermic::FactoryWrapper<IDot>& factory_wrapper,
                IPlayingFieldValidator_Ptr validator )
                : m_validator(validator)
                  , m_field(nullptr)
                  , m_rows(Row(0))
                  , m_columns(Column(0))
                  , m_factory(factory_wrapper.getFactory())
            {
            }

            ~PlayingField ()
            {
                // todo free memory
            }

            void initialize (
                const Row rows,
                const Column columns ) override;

            Row get_rows () const override;
            Column get_columns () const override;

            IPlayingFieldObject_Ptr get_object_at (
                const Row row,
                const Column column ) override;

            PlayingFieldObjectType get_object_type_at (
                const Row row,
                const Column column ) override;

            void put_object_at (
                const IPlayingFieldObject_Ptr object,
                const Row row,
                const Column column ) override;

            void move_object_from_to (
                const Row from_row,
                const Column from_column,
                const Row to_row,
                const Column to_column ) override;
        };
    };
};
