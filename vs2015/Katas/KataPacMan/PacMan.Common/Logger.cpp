#include "stdafx.h"
#include <string>
#include "Logger.h"

namespace PacMan
{
    namespace Common
    {
        void Logger::log (
            const std::string type,
            const std::string message ) const
        {
            m_ostream << type << " " << message << '\n';
        }

        void Logger::debug ( const std::string message ) const
        {
            log("DEBUG:", message);
        }

        void Logger::error ( const std::string message ) const
        {
            log("ERROR:", message);
        }

        void Logger::info ( const std::string message ) const
        {
            log("INFO:", message);
        }

        void Logger::warning ( const std::string message ) const
        {
            log("WARNING:", message);
        }
    };
};
