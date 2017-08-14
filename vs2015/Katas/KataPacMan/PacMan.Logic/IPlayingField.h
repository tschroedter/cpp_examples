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
                const Row rows,
                const Column columns ) = 0;

            virtual Row get_rows () const = 0;
            virtual Column get_columns () const = 0;

            virtual IPlayingFieldObject_Ptr get_object_at (
                const Row rows,
                const Column columns ) = 0;

            virtual PlayingFieldObjectType get_object_type_at (
                const Row row,
                const Column column ) = 0;

            virtual void put_object_at (
                const IPlayingFieldObject_Ptr object,
                const Row row,
                const Column column ) = 0;

            virtual void move_object_from_to (
                const Row from_row,
                const Column from_column,
                const Row to_row,
                const Column to_column ) = 0;
        };

        typedef std::shared_ptr<IPlayingField> IPlayingField_Ptr;
    };
};
