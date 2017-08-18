#pragma once

#include <Hypodermic/ContainerBuilder.h>
#include "IInstaller.h"

class InstallerLogic
    : public IInstaller
{
public:
    void register_components ( Hypodermic::ContainerBuilder& builder ) override;
};
