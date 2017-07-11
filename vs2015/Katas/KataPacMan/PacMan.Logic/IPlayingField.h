#pragma once

#include "IPlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        class IPlayingField
        {
        public:
            virtual ~IPlayingField () = default;

            virtual void initialize (
                const size_t rows,
                const size_t columns ) = 0;

            virtual size_t get_rows () const = 0;
            virtual size_t get_columns () const = 0;

            virtual IPlayingFieldObject_Ptr get_object_at (
                const size_t rows,
                const size_t columns ) = 0;

            virtual PlayingFieldObjectType get_object_type_at (
                const size_t row,
                const size_t column ) = 0;

            virtual void put_object_at (
                const IPlayingFieldObject_Ptr object,
                const size_t row,
                const size_t column ) = 0;

            virtual void move_object_from_to(
                const size_t from_row,
                const size_t from_column,
                const size_t to_row,
                const size_t to_column) = 0;
        };

        typedef std::shared_ptr<IPlayingField> IPlayingField_Ptr;
    };
};
