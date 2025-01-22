#include "Stick.h"

Stick::Stick(const char* name, int damage, Grade grade)
	: Weapon::Weapon(name, damage, grade)
{
}

int Stick::getDamage()
{
	if (charges != 0)
	{
		charges--;
		return Weapon::getDamage() * 2;
	}
	return Weapon::getDamage();
}
