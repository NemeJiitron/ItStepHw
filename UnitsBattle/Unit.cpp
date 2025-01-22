	#include "Unit.h"

Unit::Unit(const char* name, int hitpoints)
	 : _name(name), _hitpoints(hitpoints)
{
	_weapon = nullptr;
}

Unit::Unit(const char* name, int hitpoints, Weapon& weapon)
	: _name(name), _hitpoints(hitpoints)
{
	_weapon = &weapon;
}

void Unit::GetHit(int damage)
{
	if (isAlive)
	{
		if (isInDefense)
		{
			damage /= 2;
		}
		_hitpoints -= damage;
		if (_hitpoints <= 0)
		{
			isAlive = false;
			std::cout << _name << " is dead" << std::endl;
		}
	}
}

int Unit::Attack(Unit& other)
{
	int damage = _weapon->getDamage();
	return damage;
}

bool Unit::Defense()
{
	return !isInDefense;
}



