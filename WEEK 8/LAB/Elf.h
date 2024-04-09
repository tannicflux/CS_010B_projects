#ifndef ELF_H
#define ELF_H

#include "Character.h"

class Elf : public Character {
private:
    std::string family;

public:
    Elf(const std::string &name, double health, double attackStrength, const std::string &family);
    void attack(Character &opponent);
};

#endif