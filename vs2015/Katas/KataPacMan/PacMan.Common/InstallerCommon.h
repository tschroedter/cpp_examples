#pragma once
#include <Hypodermic/ContainerBuilder.h>
#include "IInstaller.h"

namespace PacMan
{
    namespace Common
    {
        class InstallerCommon
            : public IInstaller
        {
        public:

            void register_components ( Hypodermic::ContainerBuilder& builder ) override;
        };
    };
};
