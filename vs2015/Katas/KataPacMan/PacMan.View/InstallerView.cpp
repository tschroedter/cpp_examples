#include "stdafx.h"
#include <Hypodermic/ContainerBuilder.h>
#include "DisplayUnknown.h"
#include "DisplayDot.h"
#include "DisplayWall.h"
#include "DisplayPacMan.h"
#include "DisplayMonster.h"
#include "DisplayMax.h"
#include "ObjectToDisplayFieldObject.h"
#include "DisplayPlayingField.h"
#include "InstallerView.h"

using namespace PacMan::View;

void InstallerView::register_components (
    Hypodermic::ContainerBuilder& builder )
{
    builder.registerType<DisplayUnknown>()
           .as<IDisplayUnknown>();

    builder.registerType<DisplayDot>()
           .as<IDisplayDot>();

    builder.registerType<DisplayWall>()
           .as<IDisplayWall>();

    builder.registerType<DisplayPacMan>()
           .as<IDisplayPacMan>();

    builder.registerType<DisplayMonster>()
           .as<IDisplayMonster>();

    builder.registerType<DisplayMax>()
           .as<IDisplayMax>();

    builder.registerType<ObjectToDisplayFieldObject>()
           .as<IObjectToDisplayFieldObject>();

    builder.registerType<DisplayPlayingField>()
           .as<IDisplayPlayingField>();
}
