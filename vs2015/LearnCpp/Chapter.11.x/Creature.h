#pragma once
#include <string>

class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int m_amount_health;
    int m_amount_attack_damage;
    int m_amount_gold;
public:
    Creature(
        std::string name,
        char symbol,
        int amount_health,
        int amount_attack_damage,
        int amount_gold)
        : m_name(name)
        , m_symbol(symbol)
        , m_amount_health(amount_health)
        , m_amount_attack_damage(amount_attack_damage)
        , m_amount_gold(amount_gold)
    {
    }

    std::string getName() const
    {
        return m_name;
    }

    char getSymbol() const
    {
        return m_symbol;
    }

    int getHealth() const
    {
        return m_amount_health;
    }

    void reduceHealth(const int health)
    {
        m_amount_health -= health;
    }

    int getDamage() const
    {
        return m_amount_attack_damage;
    }

    void setDamage(const int damage)
    {
        m_amount_attack_damage = damage;
    }

    int getGold() const
    {
        return m_amount_gold;
    }

    void addGold(const int gold)
    {
        m_amount_gold += gold;
    }

    bool isDead() const
    {
        return m_amount_health <= 0;
    }
};
