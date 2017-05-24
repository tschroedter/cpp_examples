#pragma once
#include "Creature.h"

class Monster : public Creature
{
private:
    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
                                                                                     // evenly distribute the random number across our range
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

public:
    enum Type
    {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    };

    struct MonsterData
    {
        std::string m_name;
        char m_symbol;
        int m_amount_health;
        int m_amount_attack_damage;
        int m_amount_gold;
    };

    static MonsterData monsterData[MAX_TYPES];

    Monster(Type type)
        : Creature(
            monsterData[type].m_name,
            monsterData[type].m_symbol,
            monsterData[type].m_amount_health,
            monsterData[type].m_amount_attack_damage,
            monsterData[type].m_amount_gold)
    {
    }

    static Monster getRandomMonster()
    {
        int typeAsInteger = getRandomNumber(0, MAX_TYPES - 1);
        Type type = static_cast<Type>(typeAsInteger);

        return Monster(type);
    }
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
    { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 }
};
