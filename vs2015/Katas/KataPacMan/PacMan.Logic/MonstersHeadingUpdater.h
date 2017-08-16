#pragma once
#include "IMonstersHeadingUpdater.h"
#include "IMonsterHeadingCalculator.h"
#include "ILocator.h"

namespace PacMan
{
    namespace Logic
    {
        class MonstersHeadingUpdater
            : public IMonstersHeadingUpdater
        {
        private:
            ILocator_Ptr m_locator;
            IMonsterHeadingCalculator_Ptr m_calculator;
            IPlayingField_Ptr m_playing_field;

            ILocatorInformation_Ptr get_pacman () const;
            void calculate_and_update_monster ( ILocatorInformation_Ptr info ) const;
            void calculate_and_update_all_monsters () const;

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
