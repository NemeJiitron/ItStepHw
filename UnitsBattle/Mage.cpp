#include "Mage.h"

Mage::Mage(const char* name, int hitpoints, Stick& stick)
	: Unit::Unit(name, hitpoints, 2, stick), mana(100)
{
}

int Mage::Attack(Unit& other)
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
	DamageMessage(other, damage);
	other.GetHit(damage);
	return damage;
}
