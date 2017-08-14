#pragma once
#include <memory>
#include "PlayingFieldObjectType.h"
#include "RowAndColumn.h"

namespace PacMan
{
    namespace Logic
    {
        class IMoveObjectInformation
        {
        public:
            virtual ~IMoveObjectInformation () = default;

            Row from_row;
            Column from_column;
            Row to_row;
            Column to_column;
            PlayingFieldObjectType playing_field_object_type;
        };

        typedef std::shared_ptr<IMoveObjectInformation> IMoveObjectInformation_Ptr;
    };
};
