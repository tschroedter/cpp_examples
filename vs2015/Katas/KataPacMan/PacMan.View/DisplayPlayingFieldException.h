#pragma once

#include <string>
#include "../PacMan.Common/BaseException.h"

namespace PacMan
{
    namespace View
    {
        class DisplayPlayingFieldException
            : public Common::BaseException
        {
        public:
            explicit DisplayPlayingFieldException ( const std::string& error )
                : BaseException(error)
            {
            }
        };
    };
};
