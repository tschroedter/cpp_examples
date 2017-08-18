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

            virtual void debug ( const std::string message ) const = 0;
            virtual void error ( const std::string message ) const = 0;
            virtual void info ( const std::string message ) const = 0;
            virtual void warning ( const std::string message ) const = 0;
        };

        typedef std::shared_ptr<ILogger> ILogger_Ptr;
    };
};
