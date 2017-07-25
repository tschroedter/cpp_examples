#include "stdafx.h"
#include <Hypodermic/ContainerBuilder.h>
#include "IIOCContainerBuilder.h"
#include "IOCContainerBuilder.h"
#include "ILogger.h"
#include "Logger.h"
#include "PlayingFieldValidator.h"
#include "PlayingField.h"
#include "Dot.h"
#include "IPacMan.h"
#include "PacMan.h"
#include "DisplayPlayingField.h"
#include "Location.h"
#include "Direction.h"
#include "DisplayUnknown.h"
#include "DisplayMonster.h"
#include "DisplayMax.h"
#include "Monster.h"
#include "IObjectToDisplayFieldObject.h"
#include "ObjectToDisplayFieldObject.h"
#include "DisplayDot.h"
#include "DisplayPacMan.h"
#include "InputMoveForPacMan.h"
#include "GameTimer.h"
#include "ObjectMover.h"
#include "ObjectMoveCalculator.h"
#include "ObjectsMover.h"

namespace PacMan
{
    namespace Logic
    {
        class IInputPacManMove;
    }

    namespace View
    {
        class IViewPlayingField;
    }

    namespace Match
    {
        void IOCContainerBuilder::register_components (
            Hypodermic::ContainerBuilder& builder )
        {
            using namespace Logic;

            builder.registerType<Common::Logger>()
                   .as<Common::ILogger>();

            builder.registerType<PlayingFieldValidator>()
                   .as<IPlayingFieldValidator>();

            builder.registerType<ObjectMover>()
                   .as<IObjectMover>();

            builder.registerType<ObjectsMover>()
                   .as<IObjectsMover>();

            builder.registerType<ObjectMoveCalculator>()
                   .as<IObjectMoveCalculator>();

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

            builder.registerType<PacMan>()
                   .as<IPacMan>();

            builder.registerType<Monster>()
                   .as<IMonster>();

            builder.registerType<InputPacManMove>()
                   .as<IInputPacManMove>();

            builder.registerType<GameTimer>()
                   .as<IGameTimer>();

            builder.registerType<View::DisplayUnknown>()
                   .as<View::IDisplayUnknown>();

            builder.registerType<View::DisplayDot>()
                   .as<View::IDisplayDot>();

            builder.registerType<View::DisplayPacMan>()
                   .as<View::IDisplayPacMan>();

            builder.registerType<View::DisplayMonster>()
                   .as<View::IDisplayMonster>();

            builder.registerType<View::DisplayMax>()
                   .as<View::IDisplayMax>();

            builder.registerType<View::ObjectToDisplayFieldObject>()
                   .as<View::IObjectToDisplayFieldObject>();

            builder.registerType<View::DisplayPlayingField>()
                   .as<View::IDisplayPlayingField>();
        }

        Container_Ptr IOCContainerBuilder::build ()
        {
            Hypodermic::ContainerBuilder builder;

            using namespace Match;
            {
                register_components(builder);

                Container_Ptr container = builder.build();

                return container;
            }
        }
    };
};
