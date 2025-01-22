#pragma once
#include "Weapon.h"
class Bow : public Weapon
{
protected:
    size_t _max_damage;
public:
    Bow(const char* name, int damage, Grade grade, size_t max_damage);
    int getDamage();
};

