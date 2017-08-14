#pragma once
#include <memory>
#include "Heading.h"
#include "RowAndColumn.h"

namespace PacMan
{
    namespace Logic
    {
        class IMonsterHeadingCalculator
        {
        public:
            virtual ~IMonsterHeadingCalculator() = default;

            virtual void calculate() = 0;
            virtual Heading get_heading() const = 0;

            Row monster_row{ 0 };
            Column monster_column{ 0 };
            Row pacman_row{ 0 };
            Column pacman_column{ 0 };
        };

        typedef std::shared_ptr<IMonsterHeadingCalculator> IMonsterHeadingCalculator_Ptr;
    };
};