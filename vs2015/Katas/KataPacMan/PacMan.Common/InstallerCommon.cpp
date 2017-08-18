#include "stdafx.h"
#include "InstallerCommon.h"
#include <Hypodermic/ContainerBuilder.h>
#include "ILogger.h"
#include "Logger.h"

namespace PacMan
{
    namespace Common
    {
        void InstallerCommon::register_components (
            Hypodermic::ContainerBuilder& builder )
        {
            builder.registerType<Logger>()
                   .as<ILogger>();
        }
    };
};
