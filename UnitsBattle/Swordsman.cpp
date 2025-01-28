#include "Swordsman.h"


Swordsman::Swordsman(const char* name, int hitpoints, Sword& sword, unsigned int pwr)
	:Unit::Unit(name, hitpoints, 30, sword), power(pwr)
{
}

int Swordsman::Attack(Unit& other)
{
	int damage = Unit::Attack(other);
	if (damage == -1)
	{
		return damage;
	}
	damage = (damage * power) - damage;
	other.GetHit(damage);
	return damage;
}
