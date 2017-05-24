#pragma once
#include <iostream>
#include "Player.h"
#include "Monster.h"

class Game
{
private:
    Player* m_player;

    static int getRandomNumber(int min, int max)
    { // todo remove duplicated code
        static const double fraction = 1.0 / (static_cast<double> (RAND_MAX) + 1.0); // static used for efficiency, so we only calculate this value once
                                                                                     // evenly distribute the random number across our range
        return static_cast<int> (rand() * fraction * (max - min + 1) + min);
    }

    static inline char getPlayerChoice()
    {
        char choice;
        do
        {
            std::cin >> choice;
        } while (choice != 'r' && choice != 'f');

        return choice;
    }

    void attack_monster(Monster& monster) const
    {
        std::cout << "You hit the " << monster.getName() << " for " << m_player->getDamage() << " damage." << "\n";
        monster.reduceHealth(m_player->getDamage());

        if (monster.isDead())
        {
            m_player->levelUp();

            std::cout << "You killed the " << monster.getName() << "!" << "\n";
            std::cout << "You are now level " << m_player->getLevel() << "!" << "\n";
        }
    }

    void attack_player(const Monster& monster) const
    {
        std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage." << "\n";
        m_player->reduceHealth(monster.getDamage());

        if (m_player->isDead())
        {
            std::cout << "You killed the " << monster.getName() << "!" << "\n";
            std::cout << "You died at level " << m_player->getLevel() << " and with " << m_player->getGold() << " gold." << "\n";
        }
    }

    void player_runs(const Monster& monster) const
    {
        bool has_escaped = getRandomNumber(0, 1) == 1;

        if (has_escaped)
        {
            std::cout << "You successfully fled." << "\n";
        }
        else
        {
            std::cout << "You failed to flee." << "\n";
            attack_player(monster);
        }
    }

    void player_fights(Monster& monster) const
    {
        attack_monster(monster);

        if (!monster.isDead())
        {
            attack_player(monster);
        }
    }

    void player_finds_gold() const
    {
        int gold = getRandomNumber(0, 100);

        m_player->addGold(gold);

        std::cout << "You found " << gold << " gold." << "\n";
    }

    void play_one_round() const
    {
        Monster monster = Monster::getRandomMonster();

        std::cout << "You have encountered a " << monster.getName() << "\n";

        std::cout << "(R)un or (F)ight: ";
        char choice = getPlayerChoice();

        if ('f' == choice)
        {
            player_fights(monster);
        }
        else
        {
            player_runs(monster);
        }

        player_finds_gold();
    }

public:
    Game(std::string player_name)
    {
        m_player = new Player{ player_name };
    }

    void play() const
    {
        std::cout << "Welcome, " << m_player->getName() << "\n";

        while (!m_player->isDead() || m_player->getLevel() >= 20)
        {
            play_one_round();
        }
    }
};
