#pragma once
#include "IDisplayPlayingFieldObject.h"
#include <memory>

namespace PacMan
{
    namespace View
    {
        class IDisplayDot
            : public IDisplayPlayingFieldObject
        {
        public:
            virtual ~IDisplayDot () = default;
        };

        typedef std::shared_ptr<IDisplayDot> IDisplayPlayingFieldDot_Ptr;
    };
};
