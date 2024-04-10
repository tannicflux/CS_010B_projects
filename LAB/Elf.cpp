#include "Elf.h"
#include <iostream>

Elf::Elf(const std::string &name, double health, double attackStrength, const std::string &family) : Character(ELF, name, health, attackStrength), family(family) {}

void Elf::attack(Character &opponent) {
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if (opp.family == this->family) {
            std::cout << "Elf " << this->name << " does not attack Elf " << opp.name << "." << std::endl;
            std::cout << "They are both members of the " << this->family << " family." << std::endl;
        } else {
            double damage = (this->health / MAX_HEALTH) * this->attackStrength;
            opp.damage(damage);
            std::cout << "Elf " << this->name << " shoots an arrow at " << opp.name << " --- TWANG!!" << std::endl;
            std::cout << opp.name << " takes " << damage << " damage." << std::endl;
        }
    } else {
        double damage = (this->health / MAX_HEALTH) * this->attackStrength;
        opponent.damage(damage);
        std::cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << std::endl;
        std::cout << opponent.getName() << " takes " << damage << " damage." << std::endl;
    }
}