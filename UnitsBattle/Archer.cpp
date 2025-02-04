#include "Archer.h"


namespace Units {

	Archer::Archer(const char* name, int hitpoints, Weapons::Bow& bow)
		: Unit::Unit(name, hitpoints, 20, bow)
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
			other.GetHit(damage);
			if (!other.isAlive())
			{
				arrows += 5;

			}
		}
		return damage;
	}

}