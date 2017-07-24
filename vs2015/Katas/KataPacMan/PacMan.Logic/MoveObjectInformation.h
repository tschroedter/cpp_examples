#pragma once
#include "ObjectsMover.h"

namespace PacMan
{
    namespace Logic
    {
        class MoveObjectInformation
        {
        public:

            size_t from_row;
            size_t from_column;
            size_t to_row;
            size_t to_column;
            PlayingFieldObjectType playing_field_object_type;
        };
    }
}
