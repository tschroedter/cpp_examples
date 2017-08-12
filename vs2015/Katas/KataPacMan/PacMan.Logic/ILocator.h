#pragma once
#include <memory>
#include "IPlayingField.h"
#include "ILocatorInformation.h"

namespace PacMan
{
    namespace Logic
    {
        class ILocator
        {
        public:
            virtual ~ILocator() = default;

            virtual void initialize(const IPlayingField_Ptr& playing_field) = 0;
            virtual LocatorInformationVector_Ptr get_all() const = 0;
            virtual LocatorInformationVector_Ptr get_all_of_type(PlayingFieldObjectType type) const = 0;

        };

        typedef std::shared_ptr<ILocator> ILocator_Ptr;
    };
};