#pragma once
#include <memory>
#include "Heading.h"

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

            size_t monster_row{ 0 };
            size_t monster_column{ 0 };
            size_t pacman_row{ 0 };
            size_t pacman_column{ 0 };
        };

        typedef std::shared_ptr<IMonsterHeadingCalculator> IMonsterHeadingCalculator_Ptr;
    };
};