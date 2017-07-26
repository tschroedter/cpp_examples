#pragma once
#include "IDisplayPlayingFieldObject.h"
#include <memory>

namespace PacMan
{
    namespace View
    {
        class IDisplayUnknown
            : public IDisplayPlayingFieldObject
        {
        public:
            virtual ~IDisplayUnknown () = default;
        };

        typedef std::shared_ptr<IDisplayUnknown> IDisplayUnknown_Ptr;
    };
};
