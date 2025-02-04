#include "Mage.h"

namespace Units {

	Mage::Mage(const char* name, int hitpoints, Weapons::Stick& stick)
		: Unit::Unit(name, hitpoints, 10, stick), mana(100)
	{
	}

	int Mage::Attack(Unit& other)
	{
		int damage = Unit::Attack(other);
		if (damage == -1)
		{
			return damage;
		}
		other.GetHit(damage);
		return damage;
	}

}