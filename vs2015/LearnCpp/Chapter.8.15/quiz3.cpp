#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

class Monster
{
public:
    enum MonsterType
    {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES
    };

    Monster(MonsterType type,
        std::string name,
        std::string roar,
        int hitPoints)
        : m_Type(type), m_Name(name), m_Roar(roar), m_HitPoints(hitPoints)
    {
    }

    void print()
    {
        std::cout 
        << m_Name
        << " the " 
        << getTypeString() 
        << " has " 
        << m_HitPoints 
        << " hit points and says " 
        << m_Roar 
        << "\n";
    }

private:
    MonsterType m_Type;
    std::string m_Name;
    std::string m_Roar;
    int m_HitPoints;

    std::string getTypeString()
    {
        switch(m_Type)
        {
        case Dragon:
            return "Dragon";
        case Goblin:
            return "Goblin";
        case Ogre:
            return "Ogre";
        case Orc:
            return "Orc";
        case Skeleton:
            return "Skeleton";
        case Troll:
            return "Troll";
        case Vampire:
            return "Vampire";
        case Zombie:
            return "Zombie";
        default:
            return "Unknown";
        }
    }
};

class MonsterGenerator
{
public:
    static Monster generateMonster()
    {
        int randomType = getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1);
        int randomName = getRandomNumber(0, 5);
        int randomRoar = getRandomNumber(0, 5);
        int randomHitpoints = getRandomNumber(0, 100);

        static std::string s_Names[6]{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
        static std::string s_Roars[6]{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };

        Monster monster = Monster(
            static_cast<Monster::MonsterType>(randomType),
            s_Names[randomName],
            s_Roars[randomRoar],
            randomHitpoints);
        return monster;
    }

    // Generate a random number between min and max (inclusive)
    // Assumes srand() has already been called
    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
                                                                                     // evenly distribute the random number across our range
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }
};

void quiz3()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock

    Monster m = MonsterGenerator::generateMonster();
    m.print();
}

/*
 * 3) Let’s create a random monster generator. This one should be fun.
 * 3a) First, let’s create an enumeration of monster types named MonsterType. Include the 
 * following monster types: 
 * Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie. 
 * 
 * Add an additional MAX_MONSTER_TYPES enum so we can count how many enumerators there are.
 * 
 * 3b) Now, let’s create our Monster class. Our Monster will have 4 attributes (member variables): 
 * a type (MonsterType), 
 * a name (std::string), 
 * a roar (std::string), 
 * and the number of hit points (int). 
 * 
 * Create a Monster class that has these 4 member variables.
 * 
 * 3c) enum MonsterType is specific to Monster, so move the enum inside the class as a public declaration.
 * 
 * 3d) Create a constructor that allows you to initialize all of the member variables.
 * 
 * 3e) Now we want to be able to print our monster so we can validate it’s correct. To do that, we’re going 
 *     to need to write a function that converts a MonsterType into a std::string. Write that function 
 *     (called getTypeString()), as well as a print() member function.
 * 
 * 3f) Now we can create a random monster generator. Let’s consider how our MonsterGenerator class will work. 
 *     Ideally, we’ll ask it to give us a Monster, and it will create a random one for us. We don’t need more 
 *     than one MonsterGenerator. This is a good candidate for a static class (one in which all functions are static). 
 *     Create an empty MonsterGenerator class. Create a static function named generateMonster(). This should return a 
 *     Monster. For now, make it return anonymous Monster(Monster::Skeleton, “Bones”, “*rattle*”, 4);
 *     
 * 3g) Now, MonsterGenerator needs to generate some random attributes. To do that, we’ll need to make use of this handy function:
 */