#include "Swordsman.h"


Swordsman::Swordsman(const char* name, int hitpoints, Sword& sword, unsigned int pwr)
	:Unit::Unit(name, hitpoints, sword), power(pwr)
{
}

int Swordsman::Attack(Unit& other)
{
	int damage = Unit::Attack(other);
	damage = (damage * power) - damage;
	other.GetHit(damage);
	return damage;
}
