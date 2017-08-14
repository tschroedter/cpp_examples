#pragma once
#include "ILocator.h"
#include <functional>

namespace PacMan
{
    namespace Logic
    {
        class Locator
            : public ILocator
        {
        private:
            IPlayingField_Ptr m_playing_field;
            LocatorInformationVector_Ptr get_all_with_filter (
                std::function<bool  ( IPlayingFieldObject_Ptr& )> func ) const;

        public:
            Locator () = default;
            ~Locator () = default;

            void initialize ( const IPlayingField_Ptr& playing_field ) override;
            LocatorInformationVector_Ptr get_all () const override;
            LocatorInformationVector_Ptr get_all_of_type ( PlayingFieldObjectType type ) const override;
        };
    };
};
