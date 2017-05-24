#pragma once

#include <memory>
#include "IPlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        class IDot
                :public IPlayingFieldObject
        {
        public:
            virtual ~IDot () = default;
        };

        typedef std::shared_ptr<IDot> IDot_Ptr;
    };
};
