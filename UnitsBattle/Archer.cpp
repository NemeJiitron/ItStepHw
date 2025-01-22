#include "Archer.h"

Archer::Archer(const char* name, int hitpoints, Bow& bow)
	: Unit::Unit(name, hitpoints, bow)
{
}

int Archer::Attack(Unit& other)
{
	int damage = Unit::Attack(other);
	if (arrows)
	{
		other.GetHit(damage);

	}
	return damage;
}
