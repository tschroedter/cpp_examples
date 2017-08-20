#pragma once
#include "RowAndColumn.h"
#include "IObjectMoveCalculator.h"
#include "IToRowAnToColumnCalculator.h"

namespace PacMan
{
    namespace Logic
    {
        class ToRowAnToColumnCalculator
            : public IToRowAnToColumnCalculator
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

            void caclulate () override;
        };
    };
};
