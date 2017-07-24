#pragma once
#include <memory>
#include "PlayingFieldObjectType.h"

namespace PacMan
{
    namespace Logic
    {
        class IMovingObjectsRepository
        {
        public:
            virtual ~IMovingObjectsRepository () = default;
            virtual void add ( size_t row, size_t column, size_t to_row, size_t to_column, PlayingFieldObjectType get_type ) = 0;
            void clear ();
        };

        typedef std::shared_ptr<IMovingObjectsRepository> IMovingObjectsRepository_Ptr;
    }
}
