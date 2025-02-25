#include "enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(string enemyName, int hp, int attack)
    : name(enemyName), health(hp), attackPower(attack) {
} 

void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    cout << name << " takes " << damage << " damage! Health: " << health << endl;
}

bool Enemy::isAlive() const { 
    return health > 0;
}

int Enemy::attack() const { 
    return attackPower;
}

void Enemy::displayStats() const { 
    cout << "\nEnemy: " << name << "\nHealth: " << health << "\nAttack Power: " << attackPower << endl;
}

string Enemy::getName() const { 
    return name;
}
