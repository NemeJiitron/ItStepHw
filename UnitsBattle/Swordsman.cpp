#include "Swordsman.h"


Swordsman::Swordsman(const char* name, int hitpoints, Sword& sword, unsigned int pwr)
	:Unit::Unit(name, hitpoints, 3, sword), power(pwr)
{
}

int Swordsman::Attack(Unit& other)
{
	int damage = Unit::Attack(other);
	if (damage == -1)
	{
		return damage;
	}
	if (other.isInDefense())
	{
		damage /= other.getArmor();
	}
	damage = (damage * power) - damage;
	DamageMessage(other, damage);
	other.GetHit(damage);
	return damage;
}
