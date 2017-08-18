#pragma once

#include <Hypodermic/ContainerBuilder.h>

class IInstaller
{
public:
    virtual ~IInstaller () = default;

    virtual void register_components ( Hypodermic::ContainerBuilder& builder ) = 0;
};
