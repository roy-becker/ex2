#ifndef EX2_Player_H
#define EX2_Player_H

#include <string>


class Player 
{
public:
    /*
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param maxHP - The maximum HP of the player (also its starting HP).
     * @param force - The initial force of the player.
     * @return
     *      A new instance of Player.
    */
    Player(const std::string& name, int maxHP = 100, int force = 5);

    /*
     * Copy C'tor of Player class
     *
     * @param player - The player instance to be copied.
     * @return
     *      A new instance of Player.
    */
    Player(const Player& player) = default;

    /*
     * D'tor of Player class
    */
    ~Player() = default;

    /*
     * = operator of Player class
     *
     * @param player - The other player to be assigned to this player.
    */
    Player& operator=(const Player& player) = default;

    /*
     * Prints info about the player like so:
     *
     * Player Details :
     * Name: <name>
     * Level: <level>
     * Force: <force>
     * HP: <HP>
     * Coins: <coins>
     * ------------------------
     * 
     * @return
     *      void
    */
    void printInfo();

    /*
     * Levels the player up by one level (unless they're already level 10)
     *
     * @return
     *      void
    */
    void levelUp();

    /*
     * Return the current level of the player
     *
     * @return
     *      The player's current level.
    */
    int getLevel();

    /*
     * Buffs the player's attack force by the given value.
     *
     * @param amount - The amount to buff the player by.
     * @return
     *      void
    */
    void buff(int amount);

    /*
     * Heals the player by the given value.
     *
     * @param amount - The amount to heal the player by.
     * @return
     *      void
    */
    void heal(int amount);

    /*
     * Damages the player by the given value.
     *
     * @param amount - The amount to damage the player by.
     * @return
     *      void
    */
    void damage(int amount);

    /*
     * Checks if the player is knocked out.
     *
     * @return
     *      Whether the player is knocked out or not.
    */
    bool isKnockedOut();

    /*
     * Gives the player an amount of coins determined by the given value.
     *
     * @param amount - The amount to give the player by.
     * @return
     *      void
    */
    void addCoins(int amount);
    
     /*
     * Makes the player pay an amount of coins determined by the given value.
     *
     * @param amount - The amount to make the player pay.
     * @return
     *      void
    */
    void pay(int amount);

     /*
     * Return the current attack force of the player
     *
     * @return
     *      The player's current attack force.
    */
    int getAttackStrength();


private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

};


#endif //EX2_Player_H