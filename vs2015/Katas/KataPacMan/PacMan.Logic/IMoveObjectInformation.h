#pragma once
#include <memory>
#include "PlayingFieldObjectType.h"

namespace PacMan
{
    namespace Logic
    {
        class IMoveObjectInformation
        {
        public:
            virtual ~IMoveObjectInformation () = default;

            size_t from_row;
            size_t from_column;
            size_t to_row;
            size_t to_column;
            PlayingFieldObjectType playing_field_object_type;
        };

        typedef std::shared_ptr<IMoveObjectInformation> IMoveObjectInformation_Ptr;
    };
};
