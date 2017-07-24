#pragma once
#include "IMovingObjectsRepository.h"

namespace PacMan
{
    namespace Logic
    {
        class MovingObjectsRepository   // todo testing
            : IMovingObjectsRepository
        {
        public:
            MovingObjectsRepository();
            ~MovingObjectsRepository() = default;

            void add(size_t row, size_t column, size_t to_row, size_t to_column, PlayingFieldObjectType get_type) override;
        };
    }
}
