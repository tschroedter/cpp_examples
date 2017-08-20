#include "stdafx.h"
#include <Hypodermic/ContainerBuilder.h>
#include "InstallerLogic.h"
#include "Locator.h"
#include "PlayingFieldValidator.h"
#include "ObjectsTicker.h"
#include "ObjectMover.h"
#include "ObjectsMover.h"
#include "ObjectsMoveExecuter.h"
#include "ObjectsMoverCalculator.h"
#include "ObjectMoveCalculator.h"
#include "ObjectsMoveValidator.h"
#include "PlayingField.h"
#include "MonsterHeadingCalculator.h"
#include "IPacMan.h"
#include "MonstersHeadingUpdater.h"
#include "IWall.h"
#include "Wall.h"
#include "Dot.h"
#include "Direction.h"
#include "Location.h"
#include "Monster.h"
#include "InputMoveForPacMan.h"
#include "GameTimer.h"
#include "PacMan.h"
#include "ToRowAnToColumnCalculator.h"

using namespace ::PacMan::Logic;

void InstallerLogic::register_components (
    Hypodermic::ContainerBuilder& builder )
{
    builder.registerType<Locator>()
           .as<ILocator>();

    builder.registerType<PlayingFieldValidator>()
           .as<IPlayingFieldValidator>();

    builder.registerType<ObjectsTicker>()
           .as<IObjectsTicker>();

    builder.registerType<ObjectMover>()
           .as<IObjectMover>();

    builder.registerType<ObjectsMover>()
           .as<IObjectsMover>();

    builder.registerType<ObjectsMoveExecuter>()
           .as<IObjectsMoveExecuter>();

    builder.registerType<ObjectsMoverCalculator>()
           .as<IObjectsMoverCalculator>();

    builder.registerType<ObjectMoveCalculator>()
           .as<IObjectMoveCalculator>();

    builder.registerType<ObjectsMoveValidator>()
           .as<IObjectsMoveValidator>();

    builder.registerType<MovingObjectsRepository>()
           .as<IMovingObjectsRepository>();

    builder.registerType<PlayingField>()
           .as<IPlayingField>();

    builder.registerType<Location>()
           .as<ILocation>();

    builder.registerType<Direction>()
           .as<IDirection>();

    builder.registerType<Dot>()
           .as<IDot>();

    builder.registerType<Wall>()
           .as<IWall>();

    builder.registerType<::PacMan::Logic::PacMan>()
           .as<IPacMan>();

    builder.registerType<MonsterHeadingCalculator>()
           .as<IMonsterHeadingCalculator>();

    builder.registerType<MonstersHeadingUpdater>()
           .as<IMonstersHeadingUpdater>();

    builder.registerType<Monster>()
           .as<IMonster>();

    builder.registerType<InputPacManMove>()
           .as<IInputPacManMove>();

    builder.registerType<GameTimer>()
           .as<IGameTimer>();

    builder.registerType<ToRowAnToColumnCalculator>()
           .as<IToRowAnToColumnCalculator>();
}
