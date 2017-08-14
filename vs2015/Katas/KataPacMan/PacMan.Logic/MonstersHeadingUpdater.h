#pragma once
#include "IMonstersHeadingUpdater.h"
#include "IMonsterHeadingCalculator.h"
#include "ILocator.h"

namespace PacMan
{
    namespace Logic
    {
        class MonstersHeadingUpdater // todo testing
            : public IMonstersHeadingUpdater
        {
        private:
            ILocator_Ptr m_locator;
            IMonsterHeadingCalculator_Ptr m_calculator;
            IPlayingField_Ptr m_playing_field;

        public:
            MonstersHeadingUpdater (
                ILocator_Ptr locator,
                IMonsterHeadingCalculator_Ptr calculator )
                : m_locator(locator),
                  m_calculator(calculator)
            {
            };

            ~MonstersHeadingUpdater () = default;

            void initialize ( const IPlayingField_Ptr& playing_field ) override;
            void update () const override;
        };
    };
};
