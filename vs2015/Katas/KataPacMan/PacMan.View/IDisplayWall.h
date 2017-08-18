#pragma once
#include "IDisplayPlayingFieldObject.h"
#include <memory>

namespace PacMan
{
    namespace View
    {
        class IDisplayWall
            : public IDisplayPlayingFieldObject
        {
        public:
            virtual ~IDisplayWall () = default;
        };

        typedef std::shared_ptr<IDisplayWall> IDisplayWall_Ptr;
    };
};
