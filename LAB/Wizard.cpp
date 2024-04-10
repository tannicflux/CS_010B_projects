#include "Wizard.h"
#include <iostream>

Wizard::Wizard(const std::string &name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength), rank(rank) {}

void Wizard::attack(Character &opponent) {
    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        double damage = this->attackStrength * (static_cast<double>(this->rank) / opp.rank);
        opp.damage(damage);
        std::cout << "Wizard " << this->name << " attacks " << opp.name << " --- POOF!!" << std::endl;
        std::cout << opp.name << " takes " << damage << " damage." << std::endl;
    } else {
        double damage = this->attackStrength;
        opponent.damage(damage);
        std::cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << std::endl;
        std::cout << opponent.getName() << " takes " << damage << " damage." << std::endl;
    }
}