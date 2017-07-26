#pragma once
#include <string>
#include "BaseException.h"

namespace PacMan
{
    namespace Logic
    {
        class PlayingFieldException
            : public Common::BaseException
        {
        public:
            explicit PlayingFieldException (
                const std::string error )
                : BaseException(error)
            {
            }
        };
    };
};
