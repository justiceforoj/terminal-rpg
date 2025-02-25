#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int health;
    int attackPower;
    int gold;
    int potions;


public:
    Player(std::string playerName);
    void takeDamage(int damage);
    void attack();
    void heal(int amount);
    void displayStats();
    bool isAlive();
	void addGold(int amount);
	void addPotion();
    int getAttackPower() const;
};

#endif
