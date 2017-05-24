#pragma once

#include <ctime>
#include "Creature.h"
#include "Monster.h"
#include "Player.h"
#include "Game.h"

inline std::string getString ()
{
    std::string choice;
    do
    {
        std::cin >> choice;
    }
    while ( choice.length() == 0 );

    return choice;
}

inline std::string getPlayerName ()
{
    std::cout << "Enter your name : ";

    return getString();
}

inline int quiz3 ()
{
    std::string playerName = getPlayerName();

    Game game { playerName };

    game.play();

    return 0;
}
