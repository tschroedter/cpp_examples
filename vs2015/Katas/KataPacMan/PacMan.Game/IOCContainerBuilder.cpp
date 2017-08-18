#include "stdafx.h"
#include <Hypodermic/ContainerBuilder.h>
#include "IIOCContainerBuilder.h"
#include "IOCContainerBuilder.h"
#include "IGame.h"
#include "InstallerLogic.h"
#include "InstallerView.h"
#include "Game.h"
#include "InstallerCommon.h"

namespace PacMan
{
    namespace Match
    {
        void IOCContainerBuilder::register_components (
            Hypodermic::ContainerBuilder& builder )
        {
            using namespace Logic;

            builder.registerType<Game>()
                   .as<IGame>();

            Common::InstallerCommon installer_common;
            installer_common.register_components(builder);

            InstallerLogic installer_logic;
            installer_logic.register_components(builder);

            InstallerView installer_view;
            installer_view.register_components(builder);
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
