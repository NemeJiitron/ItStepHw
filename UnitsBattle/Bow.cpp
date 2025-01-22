#include "Bow.h"

Bow::Bow(const char* name, int damage, Grade grade, size_t max_damage)
    : Weapon::Weapon(name, damage, grade), _max_damage(max_damage)
{
}

int Bow::getDamage()
{
    return Weapon::getDamage() + _max_damage;
}
