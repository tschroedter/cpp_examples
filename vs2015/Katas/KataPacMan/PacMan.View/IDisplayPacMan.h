#pragma once
#include "IDisplayPlayingFieldObject.h"
#include <memory>

namespace PacMan
{
    namespace View
    {
        class IDisplayPacMan
            : public IDisplayPlayingFieldObject
        {
        public:
            virtual ~IDisplayPacMan () = default;
        };

        typedef std::shared_ptr<IDisplayPacMan> IDisplayPacMan_Ptr;
    };
};
