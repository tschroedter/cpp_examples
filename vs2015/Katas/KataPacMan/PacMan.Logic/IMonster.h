#pragma once

#include "IPlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        class IMonster
            : public IPlayingFieldObject
        {
        public:
            virtual ~IMonster () = default;
        };

        typedef std::shared_ptr<IMonster> IMonster_Ptr;
    };
};
