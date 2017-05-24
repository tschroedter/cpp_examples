#pragma once

#include <string>
#include <memory>

namespace PacMan
{
    namespace Common
    {
        class ILogger
        {
        public:
            virtual ~ILogger () = default;

            virtual void debug ( std::string message ) const = 0;
            virtual void error ( std::string message ) const = 0;
            virtual void info ( std::string message ) const = 0;
            virtual void warning ( std::string message ) const = 0;
        };

        typedef std::shared_ptr<ILogger> ILogger_Ptr;
    };
};
