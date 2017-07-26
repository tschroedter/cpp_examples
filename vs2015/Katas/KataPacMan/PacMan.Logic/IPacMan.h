#pragma once

#include "IPlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        class IPacMan
            : public IPlayingFieldObject
        {
        public:
            virtual ~IPacMan () = default;
        };

        typedef std::shared_ptr<IPacMan> IPacMan_Ptr;
    };
};
