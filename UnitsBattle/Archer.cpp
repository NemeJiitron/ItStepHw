#include "Archer.h"

Archer::Archer(const char* name, int hitpoints, Bow& bow)
	: Unit::Unit(name, hitpoints, 2, bow)
{
}

int Archer::Attack(Unit& other)
{
	int damage = Unit::Attack(other);
	if (damage == -1)
	{
		return damage;
	}
	if (arrows)
	{
		if (other.isInDefense())
		{
			damage /= other.getArmor();
		}
		DamageMessage(other, damage);
		other.GetHit(damage);
		if (!other.isAlive())
		{
			arrows += 5;

		}
	}
	return damage;
}
