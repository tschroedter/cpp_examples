#pragma once
#include "IDisplayPlayingFieldObject.h"
#include <memory>

namespace PacMan
{
    namespace View
    {
        class IDisplayMax
                : public IDisplayPlayingFieldObject
        {
        public:
            virtual ~IDisplayMax () = default;
        };

        typedef std::shared_ptr<IDisplayMax> IDisplayMax_Ptr;
    };
};
