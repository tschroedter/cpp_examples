#pragma once
#include "IMonsterHeadingCalculator.h"
#include "Heading.h"

namespace PacMan
{
    namespace Logic
    {
        class MonsterHeadingCalculator
            : public IMonsterHeadingCalculator
        {
        private: 
            Heading m_heading = Heading_Unknown;

        public:
            MonsterHeadingCalculator() = default;
            ~MonsterHeadingCalculator() = default;

            int calculate_delta_row () const;
            int calculate_delta_column () const;
            void calculate() override;
            Heading get_heading() const override;
        };
    };
};
