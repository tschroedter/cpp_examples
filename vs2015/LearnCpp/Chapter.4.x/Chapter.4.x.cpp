// Chapter.4.x.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

enum class MonsterType
{
    OGRE,
    DRAGON,
    ORC,
    GIANT_SPIDER,
    SLIME
};

struct Monster
{
    MonsterType type;
    std::string name;
    int health;
};

std::string getMonsterTypeString(Monster monster)
{
    if (monster.type == MonsterType::OGRE)
        return "Ogre";
    if (monster.type == MonsterType::DRAGON)
        return "Dragon";
    if (monster.type == MonsterType::ORC)
        return "Orc";
    if (monster.type == MonsterType::GIANT_SPIDER)
        return "Giant Spider";
    if (monster.type == MonsterType::SLIME)
        return "Slime";

    return "Unknown";
}

void printMonster(Monster monster)
{
    std::cout << "Type  : " << getMonsterTypeString(monster) << "\n";
    std::cout << "Name  : " << monster.name << "\n";
    std::cout << "Health: " << monster.health << "\n";
}

int main()
{
    Monster ogre = Monster{
        MonsterType::OGRE,
        "Ogre",
        100
    };

    printMonster(ogre);

    Monster slime = Monster{
        MonsterType::SLIME,
        "Slime",
        50
    };

    printMonster(slime);

    return 0;
}

/*
 * Quiz time!
Yay.
1) In designing a game, we decide we want to have monsters, because everyone likes fighting monsters. 
Declare a struct that represents your monster. The monster should have a type that can be one of the 
following: an ogre, a dragon, an orc, a giant spider, or a slime. If you’re using C++11, use an enum 
class for this. If you’re using an older compiler, use an enumeration for this.
Each individual monster should also have a name (use a std::string), as well as an amount of health 
that represents how much damage they can take before they die. Write a function named printMonster() 
that prints out all of the struct’s members. Instantiate an ogre and a slime, initialize them using 
an initializer list, and pass them to printMonster().

Your program should produce the following output:
This Ogre is named Torg and has 145 health.
This Slime is named Blurp and has 23 health.
 */
