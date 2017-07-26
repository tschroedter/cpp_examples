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
            size_t m_rows;
            size_t m_columns;
            std::function<std::shared_ptr<IDot>  ()> m_factory;

            IPlayingFieldObject_Ptr** create_field (
                const size_t rows,
                const size_t columns ) const;
        public:
            PlayingField (
                const Hypodermic::FactoryWrapper<IDot>& factory_wrapper,
                IPlayingFieldValidator_Ptr validator )
                : m_validator(validator)
                  , m_field(nullptr)
                  , m_rows(size_t(0))
                  , m_columns(size_t(0))
                  , m_factory(factory_wrapper.getFactory())
            {
            }

            ~PlayingField ()
            {
                // todo free memory
            }

            void initialize (
                const size_t rows,
                const size_t columns ) override;

            size_t get_rows () const override;
            size_t get_columns () const override;

            IPlayingFieldObject_Ptr get_object_at (
                const size_t row,
                const size_t column ) override;

            PlayingFieldObjectType get_object_type_at (
                const size_t row,
                const size_t column ) override;

            void put_object_at (
                const IPlayingFieldObject_Ptr object,
                const size_t row,
                const size_t column ) override;

            void move_object_from_to (
                const size_t from_row,
                const size_t from_column,
                const size_t to_row,
                const size_t to_column ) override;
        };
    };
};
