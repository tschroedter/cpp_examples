#pragma once
#include "RowAndColumn.h"
#include "IObjectMoveCalculator.h"
#include "IToRowAnToColumnCalculator.h"

namespace PacMan
{
    namespace Logic
    {
        class ToRowAnToColumnCalculator
            : IToRowAnToColumnCalculator
        {
        private:
            IObjectMoveCalculator_Ptr m_calculator;
            IPlayingField_Ptr m_playing_field;

            bool is_target_a_wall ( const Row row, const Column column ) const;

        public:
            ToRowAnToColumnCalculator (
                IObjectMoveCalculator_Ptr calculator )
                : m_calculator{calculator},
                  m_playing_field{nullptr}
            {
            };
            ~ToRowAnToColumnCalculator () = default;

            void initialize (
                const IPlayingField_Ptr playing_field ) override;

            void caclulate() override;

            Heading heading = Heading_Unknown;

            Row from_row{ 0 };
            Row from_column{ 0 };

            Row to_row{ 0 };
            Row to_column{ 0 };
        };
    };
};
