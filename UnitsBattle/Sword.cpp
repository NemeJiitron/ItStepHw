#include "Sword.h"
namespace Weapons
{
	Sword::Sword(const char* name, int damage, Grade grade)
		: Weapon::Weapon(name, damage, grade)
	{
	}

	int Sword::getDamage()
	{
		return Weapon::getDamage();
	}
}
