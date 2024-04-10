#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character {
private:
    std::string allegiance;

public:
    Warrior(const std::string &name, double health, double attackStrength, const std::string &allegiance);
    void attack(Character &opponent);
};

#endif