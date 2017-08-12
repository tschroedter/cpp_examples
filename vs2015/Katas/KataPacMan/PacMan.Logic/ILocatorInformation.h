#pragma once

#include <memory>
#include <vector>
#include "IPlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        class ILocatorInformation
        {
        public:
            virtual ~ILocatorInformation () = default;

            IPlayingFieldObject_Ptr object = nullptr;
            size_t row{0};
            size_t column{0};
        };

        typedef std::shared_ptr<ILocatorInformation> ILocatorInformation_Ptr;
        typedef std::vector<ILocatorInformation_Ptr> LocatorInformationVector;
        typedef std::shared_ptr<LocatorInformationVector> LocatorInformationVector_Ptr;
    };
};
