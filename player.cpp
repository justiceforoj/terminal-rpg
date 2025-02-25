#include "player.h"
#include <iostream>

using namespace std;

Player::Player(string playerName) : name(playerName), health(100), attackPower(10), gold(0), potions(1) {}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    cout << name << " takes " << damage << " damage! Health: " << health << endl;
}

void Player::addGold(int amount) {
    gold += amount;
    cout << "You received " << amount << " gold! Total Gold: " << gold << endl;
}

void Player::addPotion() {
    potions++;
    cout << "You found a Health Potion! Total Potions: " << potions << endl;
}

int Player::getAttackPower() const {
    return attackPower;
}

void Player::attack() {
    cout << name << " attacks dealing " << attackPower << " damage!\n";
}


void Player::heal(int amount) {
    health += amount;
    if (health > 100) health = 100;
    cout << name << " heals for " << amount << " health! Current health: " << health << endl;
}


void Player::displayStats() {
    cout << "\nPlayer Stats:\n";
    cout << "Name: " << name << "\nHealth: " << health << "\nAttack Power: " << attackPower << "\nGold: " << gold << endl;
}

bool Player::isAlive() {
    return health > 0;
}

