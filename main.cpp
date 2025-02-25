#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "enemy.h"

using namespace std;

void battle(Player& player, Enemy& enemy) {
    cout << "\nA wild " << enemy.getName() << " appears!\n";
    enemy.displayStats();

    while (player.isAlive() && enemy.isAlive()) {
        cout << "\n1. Attack\n2. Heal\n3. Run Away\n";
        cout << "Choose an action: ";
        int choice;
        cin >> choice;

        if (choice == 1) { 
            enemy.takeDamage(player.getAttackPower()); 
            if (enemy.isAlive()) {
                player.takeDamage(enemy.attack()); 
            }
        }
        else if (choice == 2) {
            player.heal(20);
        }
        else if (choice == 3) {
            cout << "You ran away safely!\n";
            return;
        }
    }

    if (!player.isAlive()) {
        cout << "You have been defeated...\n";
    }
    else {
        cout << "You defeated the " << enemy.getName() << "!\n";

        
        int goldEarned = (rand() % 41) + 10; 
        player.addGold(goldEarned);

        
        if (rand() % 100 < 30) {
            player.addPotion();
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    string playerName;
    cout << "Enter your hero's name: ";
    cin >> playerName;

    Player player(playerName);
    cout << "\nWelcome, " << playerName << "! Your journey begins...\n";

    int choice;
    do {
        cout << "\n1. Explore\n2. View Stats\n3. Quit\n";
        cout << "Choose an action: ";
        cin >> choice;

        if (choice == 1) {
            if (rand() % 2 == 0) {
                Enemy enemy("Goblin", 30, 5);
                battle(player, enemy);
            }
            else {
                cout << "You find nothing...\n";
            }
        }
        else if (choice == 2) {
            player.displayStats();
        }

    } while (choice != 3);

    cout << "Thanks for playing, " << playerName << "! See you next time.\n";
    return 0;
}
