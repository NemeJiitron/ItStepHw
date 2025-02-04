#pragma once
#include "Weapon.h"

namespace Weapons
{
    class Bow : public Weapon
    {
    protected:
    public:
        Bow(const char* name, int damage, Grade grade);
        int getDamage();
    };
}

