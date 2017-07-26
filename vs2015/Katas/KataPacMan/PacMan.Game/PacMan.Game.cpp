// PacMan.Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BaseException.h"
#include "IOCContainerBuilder.h"
#include "Logger.h"
#include "Game.h"

void play_game ()
{
    using namespace PacMan::Match;

    IOCContainerBuilder builder;
    Container_Ptr container = builder.build();

    Game game{container};

    game.run();
};

int main ()
{
    using namespace PacMan::Common;

    Logger logger{std::cout};

    int return_value = 0;

    try
    {
        // memory_leak_test();
        play_game();
    }
    catch (BaseException exception)
    {
        logger.error(
                     "Abnormal termination: "
                     + exception.get_error()
                     + "\n");

        return_value = 1;
    }
    catch (...)
    {
        logger.error("Abnormal termination!!!\n");

        return_value = 1;
    }

    return return_value;
}
