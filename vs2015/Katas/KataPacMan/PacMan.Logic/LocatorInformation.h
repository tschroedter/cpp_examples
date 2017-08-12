#pragma once
#include "ILocatorInformation.h"

namespace PacMan
{
    namespace Logic
    {
        class LocatorInformation
            : public ILocatorInformation
        {
        public:
            LocatorInformation() = default;
            ~LocatorInformation() = default;
        };
    };
};
