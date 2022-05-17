#include "utilities.h"

const int DEFAULT_MAX_HP = 100;
const int DEFAULT_FORCE = 5;

const int STARTING_LEVEL = 1;
const int STARTING_COINS = 0;


Player::Player(const char& name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE)
{
    m_name = name;
    
    m_level = STARTING_LEVEL;
    
    if (force > 0)
    {
        m_force = force;
    }
    else
    {
        m_force = DEFAULT_FORCE;
    }
    
    if (maxHP > 0)
    {
        m_maxHP = maxHP;
        m_HP = maxHP;
    }
    else
    {
        m_maxHP = DEFAULT_MAX_HP;
        m_HP = DEFAULT_MAX_HP;
    }
    
    m_coins = STARTING_COINS;
}

void Player::levelUp()
{
    if (m_level < 10)
    {
        m_level++;
    }
}

int Player::getLevel()
{
    return m_level;
}

void Player::buff(int amount)
{
    if (amount > 0)
    {
        m_force += amount;
    }
}

void Player::heal(int amount)
{
    if (amount > 0)
    {
        if (m_HP + amount < m_maxHP)
        {
            m_HP += amount;
        }
        else
        {
            m_HP == m_maxHP;
        }
    }
}

void Player::damage(int amount)
{
    if (amount > 0)
    {
        if (m_HP - amount > 0)
        {
            m_HP -= amount;
        }
        else
        {
            m_HP = 0;
        }
    }
}

bool Player::isKnockedOut()
{
    if (m_HP == 0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int amount)
{
    if (amount > 0)
    {
        m_coins += amount;
    }
}

bool Player::pay(int amount)
{
    if (amount > 0)
    {
        if (m_coins >= amount)
        {
            m_coins -= amount;
            return true;
        }
        return false;
    }
}

int Player::getAttackStrength()
{
    return (m_level + m_force);
}

void Player::printInfo()
{
    printPlayerInfo(m_name, m_level, m_force, m_HP, m_coins);
}