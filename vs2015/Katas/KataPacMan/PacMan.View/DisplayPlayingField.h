#pragma once

#include "IObjectToDisplayFieldObject.h"
#include "IDisplayPlayingField.h"
#include "IPlayingField.h"
#include <iostream>
#include "IPlayingFieldValidator.h"

namespace PacMan
{
    namespace View
    {
        class DisplayPlayingField // todo testing, todo template see playingfield
            : public IDisplayPlayingField
        {
        private:
            Logic::IPlayingFieldValidator_Ptr m_validator;

            Logic::IPlayingField_Ptr m_playing_field;

            IObjectToDisplayFieldObject_Ptr m_mapping;
            std::ostream& m_out;

            IDisplayPlayingFieldObject_Ptr** m_field;

            static IDisplayPlayingFieldObject_Ptr** create_field (
                const size_t rows,
                const size_t columns );

            IDisplayPlayingFieldObject_Ptr get_object_at (
                const size_t row,
                const size_t column ) const;

            void put_object_at (
                const IDisplayPlayingFieldObject_Ptr object,
                const size_t row,
                const size_t column ) const;

            void update_field () const;
            void display_field () const;

        public:
            DisplayPlayingField (
                IObjectToDisplayFieldObject_Ptr mapping,
                Logic::IPlayingFieldValidator_Ptr validator,
                std::ostream& out = std::cout )
                : m_validator(validator)
                  , m_mapping(mapping)
                  , m_out(out)
                  , m_field(nullptr)
            {
            }

            ~DisplayPlayingField ()
            {
            }

            void initialize (
                const Logic::IPlayingField_Ptr playing_field ) override;

            size_t get_rows () const override;
            size_t get_columns () const override;
            void print () override;
        };
    };
};
