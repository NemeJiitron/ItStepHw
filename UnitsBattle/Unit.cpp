#include "Unit.h"

namespace Units {

	void Unit::DamageMessage(int damage)
	{
		std::cout << "Unit " << _name << " received " << damage << " damage" << std::endl;
	}

	Unit::Unit(const char* name, int hitpoints)
		: _name(name), _hitpoints(hitpoints)
	{
		_weapon = nullptr;
	}

	Unit::Unit(const char* name, int hitpoints, size_t arm, Weapons::Weapon& weapon)
		: _name(name), _hitpoints(hitpoints), armor(arm)
	{
		_weapon = &weapon;
	}

	int Unit::GetHit(int damage)
	{
		if (isAlive())
		{
			if (isInDefense())
			{
				damage -= armor;
			}
			DamageMessage(damage);
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
			std::cout << _name << " attacks " << other._name << std::endl;
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

}