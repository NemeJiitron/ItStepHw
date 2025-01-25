#include "Bow.h"

Bow::Bow(const char* name, int damage, Grade grade)
    : Weapon::Weapon(name, damage, grade)
{
}

int Bow::getDamage()
{
    return Weapon::getDamage();
}
