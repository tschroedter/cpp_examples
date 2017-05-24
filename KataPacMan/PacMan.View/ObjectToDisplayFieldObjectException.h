#pragma once

#include <string>
#include "../PacMan.Common/BaseException.h"

namespace PacMan
{
    namespace View
    {
        class ObjectToDisplayFieldObjectException
                : public Common::BaseException
        {
        public:
            explicit ObjectToDisplayFieldObjectException ( const std::string& error )
                : BaseException ( error )
            {
            }
        };
    };
};
