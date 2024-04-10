#include "Character.h"
#include "Elf.h"
#include "Warrior.h"
#include "Wizard.h"
#include <iostream>
#include <string>

using namespace std;

Character::Character(HeroType type, const string &name, double health, double attackStrength) {
    this->type = type;
    this->name = name;
    this->health = health;
    this->attackStrength = attackStrength;
}

HeroType Character::getType() const {
    return type;
}

const string &Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

void Character::damage(double d) {
    health -= d;
}

bool Character::isAlive() const {
    return getHealth() > 0;
}

void Character::attack(Character &opponent) {
    double damage = 0.0;
    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        damage = (attackStrength * (opp.getHealth() / MAX_HEALTH));
    } else if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        damage = (attackStrength * (opp.getHealth() / MAX_HEALTH));
    } else if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        damage = (attackStrength * (opp.getHealth() / MAX_HEALTH));
    }
    opponent.damage(damage);
}

// Path: Elf.cpp


