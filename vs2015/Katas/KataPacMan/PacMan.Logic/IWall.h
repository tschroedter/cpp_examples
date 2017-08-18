#pragma once

#include <memory>
#include "IPlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        class IWall
            :public IPlayingFieldObject
        {
        public:
            virtual ~IWall() = default;
        };

        typedef std::shared_ptr<IWall> IWall_Ptr;
    };
};