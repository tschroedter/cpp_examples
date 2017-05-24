#pragma once
#include "IDisplayPlayingFieldObject.h"

namespace PacMan
{
    namespace View
    {
        class IDisplayMonster
                : public IDisplayPlayingFieldObject
        {
        public:
            virtual ~IDisplayMonster () = default;
        };

        typedef std::shared_ptr<IDisplayMonster> IDisplayMonster_Ptr;
    };
};
