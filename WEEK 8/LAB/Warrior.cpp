#include "Warrior.h"
#include <iostream>

Warrior::Warrior(const std::string &name, double health, double attackStrength, const std::string &allegiance) : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) {}

void Warrior::attack(Character &opponent) {
    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (opp.allegiance == this->allegiance) {
            std::cout << "Warrior " << this->name << " does not attack Warrior " << opp.name << "." << std::endl;
            std::cout << "They share an allegiance with " << this->allegiance << "." << std::endl;
        } else {
            double damage = (this->health / MAX_HEALTH) * this->attackStrength;
            opp.damage(damage);
            std::cout << "Warrior " << this->name << " attacks " << opp.name << " --- SLASH!!" << std::endl;
            std::cout << opp.name << " takes " << damage << " damage." << std::endl;
        }
    } else {
        double damage = (this->health / MAX_HEALTH) * this->attackStrength;
        opponent.damage(damage);
        std::cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << std::endl;
        std::cout << opponent.getName() << " takes " << damage << " damage." << std::endl;
    }
}