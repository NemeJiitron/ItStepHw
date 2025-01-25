	#include "Unit.h"

void Unit::DamageMessage(Unit& other, int damage)
{
	std::cout << "Unit " << _name << " attacks " << other._name << ". Damage: " << damage << std::endl;
}

Unit::Unit(const char* name, int hitpoints)
	 : _name(name), _hitpoints(hitpoints)
{
	_weapon = nullptr;
}

Unit::Unit(const char* name, int hitpoints, size_t arm, Weapon& weapon)
	: _name(name), _hitpoints(hitpoints), armor(arm)
{
	_weapon = &weapon;
}

int Unit::GetHit(int damage)
{
	if (isAlive())
	{
		_hitpoints -= damage;
		if (_hitpoints <= 0)
		{
			_hitpoints = 0;
			std::cout << _name << " is dead" << std::endl;
		}
	}
	return _hitpoints;
}

int Unit::Attack(Unit& other)
{
	if (other.isAlive())
	{
		int damage = _weapon->getDamage();
		return damage;
	}
	std::cout << "Unit " << other._name << " can`t be attacked. " << other._name << " is dead" << std::endl;
	return -1;
}

bool Unit::isAlive()
{
	return _hitpoints > 0;
}

bool Unit::isInDefense()
{
	return InDefense;
}

int Unit::getArmor()
{
	return armor;
}

bool Unit::Defense()
{
	InDefense = !InDefense;
	return InDefense;
}



