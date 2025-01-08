#pragma once
#include "Weapon.h"
class Bow : public Weapon
{
protected:
    size_t max_damage;
public:
    int getDamage();
};

