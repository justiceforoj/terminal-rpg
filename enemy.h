#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
private:
    std::string name;
    int health;
    int attackPower;

public:
    Enemy(std::string enemyName, int hp, int attack);

    void takeDamage(int damage);
    bool isAlive() const;
    int attack() const;
    void displayStats() const;

    std::string getName() const;
};

#endif
